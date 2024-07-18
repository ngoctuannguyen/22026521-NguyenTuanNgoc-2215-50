struct Time {
    int h;
    int m;
    int s;

    Time() {
        h = 0;
        m = 0;
        s = 0;
    }

    Time(int h_, int m_, int s_) {
        h = h_;
        m = m_;
        s = s_;
    }

    int second() {
        return h * 3600 + m * 60 + s;
    }

    void print() {
        if (h < 10)
            cout << 0 << h << ":";
        else cout << h << ":";
        if (m < 10)
            cout << 0 << m << ":";
        else cout << m << ":";
        if (s < 10)
            cout << 0 << s << endl;
        else cout << s << endl;
    }
};


Time normalize(int h, int m, int s) {
    Time ans;
    int seconds = h * 3600 + m * 60 + s;
    ans.h = seconds / 3600;
    ans.m = (seconds - ans.h * 3600) / 60;
    ans.s = seconds - ans.h * 3600 - ans.m * 60;
    return ans;
}
