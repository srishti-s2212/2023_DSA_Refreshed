#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <mutex>

using namespace std;

// class TimeRange {
// public:
//     int startTime;
//     int endTime;
//     TimeRange() {
//         this->startTime = 0;
//         this->endTime = 0;
//     }
//     TimeRange(int startTime, int endTime) {
//         this->startTime = startTime;
//         this->endTime = endTime;
//     }
// };

class Meeting {
public:
    int meetingId;
    pair<int, int> timeRange;
    int roomId;
    Meeting() {}
    Meeting(pair<int, int> timeRange, int roomId) {
        this->timeRange = timeRange;
        this->roomId = roomId;
        this->meetingId = rand();
    }

public:
    int getMeetingId() {
        //cout<<"Meeting ID: "<< meetingId<<" ";
        return meetingId;
    }
};

class Room {
public:
    int roomId;
    map<int, pair<int, int>> bookedSlots;

public:
    Room(int roomId) {
        this->roomId = roomId;
    }
    // bool customSort(const pair<int,int>& p1, const std::pair<int,int>& p2)
    // {
    //     //return std::tie(p1.second, p1.first) < std::tie(p2.second, p2.first);
    //     return p1.first < p2.first;
    // }

    bool isAvailable(pair<int, int> newTimeRange) {
        if (bookedSlots.size() == 0){
            cout<<"TESTS";
            return true;
            
        }
            


        vector<pair<int, int>> tR;
        //Collection<TimeRange> tR = bookedSlots.values();
        for (auto it : bookedSlots)
            tR.push_back(it.second);

        vector<pair<int, int>> timeRanges;
        for (auto it: tR) {
            timeRanges.push_back(it);
        }

        sort(timeRanges.begin(), timeRanges.end());

        for (auto currentTimeRange : timeRanges) {
            cout<<"NEWWW: "<<newTimeRange.first;
            cout<<"Old: "<<currentTimeRange.first;
            if ((newTimeRange.first == currentTimeRange.first && newTimeRange.second == currentTimeRange.second) ||
                (newTimeRange.first >= currentTimeRange.first && newTimeRange.second < currentTimeRange.second) ||
                (newTimeRange.first >  currentTimeRange.first && newTimeRange.second <= currentTimeRange.second)
                )
                cout<<"FALSE";
                return false;
        }
    cout<<"TRUEEEE";
        return true;
    }

    void bookRoom(int meetingId, pair<int, int> timeRange) {
        bookedSlots[meetingId] = timeRange;
        cout<<endl<<"Booked Slot: <Meeting ID -> TimeRange> "<<meetingId<< " -> "<<bookedSlots[meetingId].first<<" - "<<bookedSlots[meetingId].second;
    }
};

class MeetingMgr {
private:
    static MeetingMgr* INSTANCE;
    int totalRooms;
    vector<Room> rooms; //vector of total rooms

    map<int, Meeting> scheduledMeetings; //meetingId, timeRange/Meeting

    //PrivateConstructor
    MeetingMgr(int totalRooms) {
        this->totalRooms = totalRooms;
        //rooms = new vector<int>;
        //vec = new vector<int>(size,0);
        //scheduledMeetings = new map<int, Meeting>;
        initializeRooms();
    }

   
    void initializeRooms() {
        cout<<endl<<"Room initialization: "<<endl;
        for (int i = 0; i < totalRooms; i++){
            rooms.push_back(Room(i));
            cout<<"Room id: "<<rooms.at(i).roomId<<endl;
        }
        cout<<endl;
            
    }
    public:
        static MeetingMgr* getInstance(int totalRooms);

    void scheduleMeeting(pair<int, int> timeRange) {
        for (Room room: rooms) {
            //Room room(rooms.at(i).roomId);
            if (room.isAvailable(timeRange)) {
                //cout<<"Room ID: "<<rooms.at(i).roomId<<" ";
                Meeting meeting(timeRange, room.roomId);
                scheduledMeetings[meeting.getMeetingId()] = meeting;
                room.bookRoom(meeting.getMeetingId(), timeRange);
                cout << "Room id : " << room.roomId << " booked!" << endl;
                return;
            }
        }
        cout << "No Conference Rooms available" << endl;
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
        
            cout<<endl<<"Last N Meetings: "<<endl;
            for(int i = totalScheduledMeetings - 1; i >= (totalScheduledMeetings - N); i--)
                cout<<"Meeting ID: "<<meetings[i].getMeetingId()<<", TimeRange: "<<meetings[i].timeRange.first<<" - "<<meetings[i].timeRange.second<<endl;
        } 
};
MeetingMgr* MeetingMgr::INSTANCE = NULL;
MeetingMgr* MeetingMgr::getInstance(int totalRooms) {
            if (INSTANCE == NULL){
                //mutex.lock();
                INSTANCE = new MeetingMgr(totalRooms);
                //mutex.unlock();
            } 
            return INSTANCE;
        }

int main(){
    int totalRooms = 2;
    MeetingMgr* meetingMgr = MeetingMgr::getInstance(totalRooms);

    meetingMgr->scheduleMeeting({2, 3});
    meetingMgr->scheduleMeeting({2, 3});
    // meetingMgr->scheduleMeeting({1, 2});
    // meetingMgr->scheduleMeeting({7, 8});
    // meetingMgr->scheduleMeeting({8, 9});

    int N = 3;
    meetingMgr->getLastNMeeting(N);
       
    return 0;
}