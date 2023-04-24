// Build APIs to handle meetings in a predefined set of conference rooms.

//  1. It should have a method like scheduleMeeting(timeRange)
//  2. Implement a method returning the last N scheduled meetings.

//  -> take user input as maxNumberOfRooms
//  -> 24/7 rooms booking system
 
//  [2:00 - 3:00, 4:00 - 5:00]
 
//  prevEnd = 00:00
//  o (02:00-03:00, 04:00-05:00)
 
 
//  n (01:30-02:30)
 
 
//  n (03:00-04:00)
 
//  //negatives
 
//  c1 = n.start == o.start && n.end == o.end
 
//  c2 = (n.start >= o.start && n.start < o.end)
 
//  c3 = (n.end > o.start && n.end <= o.end)
 
 
//  n.end <= o.start && n.start >= prevEnd
 
//  n.start >= prevEnd
 
 
 
//  Pointer to take care
//  1. Take your time to read the question (1 - 2 mins)
//  2. Ask as many doubts as possible - make list of scope/assumption before hand
//  3. Talk about approach - Make skeleton classes  (Both parties are aligned on solution)
//  4. Think out loud (keep talking what you are doing)
 
//  5. Start with skeletons
//  6. Define variable and method signature
//  7. Define interface for main accessing methods
//  8. Implement design pattern if required
 
 
// */

// class Meeting {
//     int meetingId;
//     TimeRange timeRange;
//     int roomId;
//     Meeting(TimeRange timeRange, int roomId) {
//         this.timeRange = timeRange;
//         this.roomId = roomId;
//         this.meetingId = this.hashCode();
//     }
   
//     public int getMeetingId() {
//         return meetingId;
//     }
   
//     public String toString() {
//         return "meeting Id : "+ meetingId +" , TimeRange : "+ timeRange +" , Roome Id : " + roomId;
//     }
// }
// // [2:00 - 3:00, 4:00 - 5:00]
// class Room {
//     int roomId;
//     private HashMap<Integer, TimeRange> bookedSlots;
   
//     Room(int roomId) {
//         this.roomId = roomId;
//         bookedSlots = new HashMap<>();
//     }
   
//     boolean isAvailable(TimeRange newTimeRange) {
//         //System.out.println(newTimeRange + " for room : " + this.roomId);
//         if (bookedSlots.size() == 0)
//             return true;
       
       
//         Collection<TimeRange> tR = bookedSlots.values();
//         List<TimeRange> timeRanges = new ArrayList<>();
//         for(TimeRange timeRange : tR) {
//             timeRanges.add(timeRange);
//         }
       
//         Collections.sort(timeRanges, (t1 , t2) -> t1.start.compareTo(t2.start));
       
//         for(TimeRange currentTimeRange : timeRanges) {
//             if ((newTimeRange.start.compareTo(currentTimeRange.start) == 0 && newTimeRange.end.compareTo(currentTimeRange.end) == 0) ||
//                 (newTimeRange.start.compareTo(currentTimeRange.start) >= 0 && newTimeRange.start.compareTo(currentTimeRange.end) < 0) ||              
//                 (newTimeRange.end.compareTo(currentTimeRange.start) > 0 && newTimeRange.end.compareTo(currentTimeRange.end) <= 0))
//                 return false;
//         }
       
//         return true;
//     }
   
//     void bookRoom(Integer meetingId, TimeRange timeRange) {
//         bookedSlots.put(meetingId, timeRange);
//     }
// }

// interface ConferenceRoomScheduling {
//      public void scheduleMeeting(TimeRange timeRange);
//      public void getLastNMeeting(int N);
// }

// class ConferenceRoomAllotingSystem implements ConferenceRoomScheduling{
//     private static ConferenceRoomAllotingSystem INSTANCE;
//     private int maxNumberOfRooms;
//     private List<Room> rooms;
//     private LinkedHashMap<Integer, Meeting> scheduledMeetings;
   
//     private ConferenceRoomAllotingSystem(int maxNumberOfRooms) {
//         this.maxNumberOfRooms = maxNumberOfRooms;
//         rooms = new ArrayList<>(maxNumberOfRooms);
//         scheduledMeetings = new LinkedHashMap<>();
//         initRooms();
//     }
   
//     private void initRooms() {
//         for(int i = 0; i < maxNumberOfRooms; i++)
//             rooms.add(new Room(i));
//     }
   
//     public static ConferenceRoomAllotingSystem getInstance(int maxNumberOfRooms) {
//         if(INSTANCE == null)
//             INSTANCE = new ConferenceRoomAllotingSystem(maxNumberOfRooms);
//         return INSTANCE;
//     }
   
//     public void scheduleMeeting(TimeRange timeRange) {
//         //todo implement multi threading support
       
//         for(Room room : rooms) {
//             if (room.isAvailable(timeRange)) {
//                 Meeting meeting = new Meeting(timeRange, room.roomId);
//                 scheduledMeetings.put(meeting.getMeetingId(), meeting);
//                 room.bookRoom(meeting.getMeetingId(), timeRange);
//                 System.out.println("Conference Room id : "+room.roomId+" booked!");
//                 return;
//             }
//         }
       
//         System.out.println("No Conference Rooms available");
//     }
   
//     public void getLastNMeeting(int N) {
//         int totalScheduledMeetings = scheduledMeetings.size();
       
//         if (totalScheduledMeetings == 0) {
//             System.out.println("No meetings scheduled");
//             return;
//         }
       
//         if (N >= totalScheduledMeetings)
//             N = totalScheduledMeetings;
       
//         Collection<Meeting> ms = scheduledMeetings.values();
//         List<Meeting> meetings = new ArrayList<>();
//         for(Meeting meeting : ms) {
//             meetings.add(meeting);
//         }
       
//         for(int i = totalScheduledMeetings - 1; i >= (totalScheduledMeetings - N); i--)
//             System.out.println(meetings.get(i).toString());
//     }
   
// }

// class TimeRange {
//     String start; // 24 hours format (HH:MM) 02:30 and 03:00
//     String end;
//     TimeRange(String start, String end) {
//         this.start = start;
//         this.end = end;
//     }
   
//     public String toString() {
//         return "(Start time = " + start + " , End Time = "+ end + ")";
//     }
// }





// // Main class should be named 'Solution'
// class Solution {
//     public static void main(String[] args) {
//         int maxNumberOfRooms = 3;
//         ConferenceRoomScheduling conferenceRoomScheduling = ConferenceRoomAllotingSystem.getInstance(maxNumberOfRooms);
//         String s1 = "02:00";
//         String e1 = "03:00";
       
//         String s2 = "04:00";
//         String e2 = "05:00";
       
//         String s3 = "01:30";
//         String e3 = "02:30";
       
//         String s4 = "03:00";
//         String e4 = "04:00";
       
       
//         conferenceRoomScheduling.scheduleMeeting(new TimeRange(s1, e1));
//         conferenceRoomScheduling.scheduleMeeting(new TimeRange(s1, e1));
//         conferenceRoomScheduling.scheduleMeeting(new TimeRange(s2, e2));
//         conferenceRoomScheduling.scheduleMeeting(new TimeRange(s3, e3));
//          conferenceRoomScheduling.scheduleMeeting(new TimeRange(s4, e4));
       
//         int N = 8;
//         conferenceRoomScheduling.getLastNMeeting(N);
       
       
       
//         // System.out.println("Hello, World");
//     }
// }

