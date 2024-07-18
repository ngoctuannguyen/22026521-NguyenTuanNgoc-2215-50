#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
    int height = 0;
    int length = 0;

    Rectangle() {
        height = 0;
        length = 0;
    }

    Rectangle(int height_, int length_) {
        height = height_;
        length = length_;
    }

    int getPerimeter() {
        if (height > 0 && length > 0)
            return (height + length) << 1;
        else return 0;
    }

    void print() {
        for (int i = 1; i <= height; ++i) {
            for (int j = 1; j <= length; ++j) {
                if (i == 1 || i == height) {
                    cout << "*";
                }
                else {
                    if (j == 1 || j == length)
                        cout << "*";
                    else cout << " ";
                }
            }
            cout << endl;
        }
    }
};


int compare(Rectangle a, Rectangle b) {
    if (a.getPerimeter() > b.getPerimeter())
        return 1;
    if (a.getPerimeter() == b.getPerimeter()) 
        return 0;
    return -1;
}

