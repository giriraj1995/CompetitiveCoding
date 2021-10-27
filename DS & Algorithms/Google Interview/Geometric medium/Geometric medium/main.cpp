//
//  main.cpp
//  Geometric medium
//
//  Created by Giriraj Saigal on 27/10/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

// To store a point in 2-D space
struct Point {
    double x, y;
};
 
// Test points. These points are the left,
// up, right and down relative neighbours
// (arranged circularly) to the
// current_point at a distance of
// test_distance from current_point
Point test_point[] = { { -1.0, 0.0 },
                       { 0.0, 1.0 },
                       { 1.0, 0.0 },
                       { 0.0, -1.0 } };
 
// Lowest Limit till which we are going
// to run the main while loop
// Lower the Limit higher the accuracy
double lower_limit = 0.01;
 
// Function to return the sum of Euclidean
// Distances
double distSum(Point p,
                        Point arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double distx = abs(arr[i].x - p.x);
        double disty = abs(arr[i].y - p.y);
        sum += sqrt((distx * distx) + (disty * disty));
    }
 
    // Return the sum of Euclidean Distances
    return sum;
}
 
// Function to calculate the required
// geometric median
void geometricMedian(Point arr[], int n)
{
 
    // Current x coordinate and y coordinate
    Point current_point;
 
    for (int i = 0; i < n; i++) {
        current_point.x += arr[i].x;
        current_point.y += arr[i].y;
    }
 
    // Here current_point becomes the
    // Geographic MidPoint
    // Or Center of Gravity of equal
    // discrete mass distributions
    current_point.x /= n;
    current_point.y /= n;
 
    // minimum_distance becomes sum of
    // all distances from MidPoint to
    // all given points
    double minimum_distance =
       distSum(current_point, arr, n);
 
    int k = 0;
    while (k < n) {
        for (int i = 0; i < n, i != k; i++) {
            Point newpoint;
            newpoint.x = arr[i].x;
            newpoint.y = arr[i].y;
            double newd =
                   distSum(newpoint, arr, n);
            if (newd < minimum_distance) {
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
            }
        }
        k++;
    }
 
    // Assume test_distance to be 1000
    double test_distance = 1000;
    int flag = 0;
 
    // Test loop for approximation starts here
    while (test_distance > lower_limit) {
 
        flag = 0;
 
        // Loop for iterating over all 4 neighbours
        for (int i = 0; i < 4; i++) {
 
            // Finding Neighbours done
            Point newpoint;
            newpoint.x = current_point.x
                 + (double)test_distance * test_point[i].x;
            newpoint.y = current_point.y
                 + (double)test_distance * test_point[i].y;
 
            // New sum of Euclidean distances
            // from the neighbor to the given
            // data points
            double newd = distSum(newpoint, arr, n);
 
            if (newd < minimum_distance) {
 
                // Approximating and changing
                // current_point
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
                flag = 1;
                break;
            }
        }
 
        // This means none of the 4 neighbours
        // has the new minimum distance, hence
        // we divide by 2 and reiterate while
        // loop for better approximation
        if (flag == 0)
            test_distance /= 2;
    }
 
    cout << "Geometric Median = ("
         << current_point.x << ", "
         << current_point.y << ")";
    cout << " with minimum distance = "
         << minimum_distance;
}

int main(int argc, const char * argv[]) {
    int n = 3;
    Point arr[n];
    arr[0].x = 27;
    arr[0].y = 90;
    arr[1].x = 99;
    arr[1].y = 75;
    arr[2].x = 99;
    arr[2].y = 38;
    geometricMedian(arr, n);
 
    return 0;
    return 0;
}
