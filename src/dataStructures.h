#ifndef dataStructures_h
#define dataStructures_h

#include <deque>
#include <opencv2/core.hpp>
#include <vector>

template <class T, std::size_t capacity>
class Ringbuffer {
    std::deque<T> buffer;

   public:
    void push_back(const T& data) {
        buffer.push_back(data);
        if (buffer.size() > capacity) {
            buffer.pop_front();
        }
    }

    bool empty() const {
        return buffer.empty();
    }

    std::size_t size() const {
        return buffer.size();
    }

    typename std::deque<T>::iterator begin() {
        return buffer.begin();
    }

    typename std::deque<T>::iterator end() {
        return buffer.end();
    }

    T& back() {
        return buffer.back();
    }
};

struct DataFrame {  // represents the available sensor information at
                    // the same time instance

    cv::Mat cameraImg;  // camera image

    std::vector<cv::KeyPoint> keypoints;  // 2D keypoints within camera image
    cv::Mat descriptors;                  // keypoint descriptors
    std::vector<cv::DMatch> kptMatches;   // keypoint matches between
                                          // previous and current frame
};

#endif /* dataStructures_h */
