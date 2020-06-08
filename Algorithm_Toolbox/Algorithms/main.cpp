
#include <iostream>
#include <queue>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size)
    {
        size_ = size;
        std::deque<int> d(size,100);
//        finish_time_(d);
        
    }

    Response Process(const Request &request)
    {
        // write your code here
        static int nw_time_stamp;
        nw_time_stamp = request.arrival_time;
        Response packet_resp(false, nw_time_stamp);
        
        //if queue is not empty
        if(!finish_time_.empty())
        {//if nw time is same as finish time dequeue data
            if (finish_time_.front() <= nw_time_stamp)
            {
                finish_time_.pop();
            }
        }
        
        
        //enqueue data if queue is not full
        if(size_ != (int)finish_time_.size())
        {
            
            if (finish_time_.empty())
            {
                finish_time_.push(request.arrival_time+request.process_time);
                packet_resp.start_time = request.arrival_time;
            }
            else
            {
                packet_resp.start_time = finish_time_.back();
                finish_time_.push(finish_time_.back()+request.process_time);
            }
        }
        else
        {
            packet_resp.dropped = true;
            packet_resp.start_time = -1;
        }
            
        //nw_time_stamp++;
        return packet_resp;
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}



