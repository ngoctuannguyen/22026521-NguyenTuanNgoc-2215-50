struct Rectangle {
    // your code goes here
    // Cac bien thanh vien
    int height;
    int length;
    // your code goes here
    // Hai ham khoi tao
    
    Rectangle() {
        height = 0;
        length = 0;
    }
    
    Rectangle(int h, int l) {
        height = h;
        length = l;
    }
    
    int getPerimeter() {
        // your code goes here
        return (height + length) << 1;
    }
    
    void print() {
        // your code goes here
        for (int i = 1; i <= height; ++i) {
            if (i != 1 && i != height) {
                for (int j = 1; j <= length; ++j) {
                    if (j == 1 || j == length) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            else {
                for (int j = 1; j <= length; ++j) {
                        cout << "*";
                }
                cout << endl;
            }
        }
    }
};

int compare(Rectangle a, Rectangle b) {
    // your code goes here
    int perimeterA = a.getPerimeter();
    int perimeterB = b.getPerimeter();
    if (perimeterA == perimeterB) {
        return 0;
    }
    else if (perimeterA > perimeterB) {
        return 1;
    }
    return -1;
}