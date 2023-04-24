#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

class TimeRange{
    public:
    int startTime;
    int endTime;
    TimeRange(){
        this->startTime = 0;
        this->endTime = 0;
    }
    TimeRange(int startTime, int endTime){
        this->startTime = startTime;
        this->endTime = endTime;
    }
};

class Meeting {
    public:
    int meetingId;
    TimeRange timeRange;
    int roomId;
    // hash<int> mystdhash;
    Meeting(){}
    Meeting(TimeRange timeRange, int roomId) {
        this->timeRange = timeRange;
        this->roomId = roomId;
        this->meetingId = rand();
    }
   
    public:
    int getMeetingId() {
        return meetingId;
    }
};

class Room {
    public:
    int roomId;
    map<int, TimeRange> bookedSlots; //<Meeting ID, TimeRange>
   
   public:
    Room(int roomId) {
        this->roomId = roomId;
        //bookedSlots = new map<int, TimeRange>;
    }
   
    bool isAvailable(TimeRange newTimeRange) {
        if (bookedSlots.size() == 0)
            return true;
       
       
        vector<TimeRange> tR;
        //Collection<TimeRange> tR = bookedSlots.values();
        for(auto it: bookedSlots)
            tR.push_back(it.second);

        vector<TimeRange> timeRanges;
        for(TimeRange timeRange : tR) {
            timeRanges.push_back(timeRange);
        }

        sort(timeRanges.begin(), timeRanges.end());

        for(TimeRange currentTimeRange : timeRanges) {
            cout<<newTimeRange.startTime<<" TESSST";

            // if((newTimeRange.startTime == currentTimeRange.startTime && newTimeRange.endTime == currentTimeRange.endTime) ||
            //    (newTimeRange.startTime >= currentTimeRange.startTime && newTimeRange.endTime < currentTimeRange.endTime) ||
            //    (newTimeRange.startTime >  currentTimeRange.startTime && newTimeRange.endTime <= currentTimeRange.endTime)
            //   )
                return false;
        }
       
        return true;
    }
   
    void bookRoom(int meetingId, TimeRange timeRange) {
        bookedSlots[meetingId] = timeRange;
    }
};

//Note: If we have vector<Room> room or vector<int> v and in constructor we initialize v = new vector<int> =>THROWS ERROR
//Illegal because new returns a pointer and in the vec is an object
//So instead we can define vector as a pointer vector<int> v* or in our class vector<Room> rooms;

//In C++, we do not need to have pointer for initializing vector.
//When we create instance of class, it is automatically called
//Default initialization is performed in three situations:
// 1) when a variable with automatic, static, or thread-local storage duration is declared with no initializer;
// 2) when an object with dynamic storage duration is created by a new-expression with no initializer;
// 3) when a base class or a non-static data member is not mentioned in a constructor initializer list and that constructor is called.
class MeetingMgr{
    private: 
        static MeetingMgr* INSTANCE;
        int totalRooms;
        vector<Room> rooms; //vector of total rooms
        
        map<int, Meeting> scheduledMeetings; 

        //PrivateConstructor
        MeetingMgr(int totalRooms) {
            this->totalRooms = totalRooms;
            //rooms = new vector<int>;
            //vec = new vector<int>(size,0);
            //scheduledMeetings = new map<int, Meeting>;
            initializeRooms();
        }

        void initializeRooms(){
            for(int i=0; i<totalRooms; i++)
                rooms.push_back(Room(i));
        }
    public:
        static MeetingMgr* getInstance(int totalRooms){
            if(INSTANCE == NULL)
                INSTANCE = new MeetingMgr(totalRooms);
            return INSTANCE;
        }  

        void scheduleMeeting(TimeRange timeRange) {
            for(Room room : rooms) {
            if (room.isAvailable(timeRange)) {
                Meeting meeting(timeRange, room.roomId);
                scheduledMeetings[meeting.getMeetingId()] = meeting;
                room.bookRoom(meeting.getMeetingId(), timeRange);
                cout<<"Conference Room id : " +room.roomId <<" booked!";
                return;
            }
            }
            cout<<"No Conference Rooms available";
        } 


        void getLastNMeeting(int N) {
            int totalScheduledMeetings = scheduledMeetings.size();
        
            if (totalScheduledMeetings == 0) {
                cout<<"No meetings scheduled";
                return;
            }
        
            if (N >= totalScheduledMeetings)
                N = totalScheduledMeetings;
        
            vector<Meeting> ms;
            for(auto it: scheduledMeetings){
                ms.push_back(it.second);
            }
            vector<Meeting> meetings;
            for(Meeting meeting : ms) {
                meetings.push_back(meeting);
            }
        
            for(int i = totalScheduledMeetings - 1; i >= (totalScheduledMeetings - N); i--)
                cout<<meetings[i].getMeetingId();
        } 
};

int main(){
    int totalRooms = 5;
    MeetingMgr* meetingMgr = MeetingMgr::getInstance(totalRooms);

    meetingMgr->scheduleMeeting(TimeRange(2, 3));
    meetingMgr->scheduleMeeting(TimeRange(4, 5));
    meetingMgr->scheduleMeeting(TimeRange(3, 4));
    meetingMgr->scheduleMeeting(TimeRange(5, 7));
    meetingMgr->scheduleMeeting(TimeRange(8, 9));

    int N = 3;
    meetingMgr->getLastNMeeting(N);
       
    return 0;
}