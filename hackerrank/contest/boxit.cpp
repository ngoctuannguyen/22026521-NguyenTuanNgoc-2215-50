#include<bits/stdc++.h>

using namespace std;

class Box {
private:    
    int l;
    int b;
    int h;
public:
    Box() {
        l = 0;
        h = 0;
        b = 0;
    }

    Box(int l, int b, int h) {
        this->l = l;
        this->b = b;
        this->h = h;
    }

    Box(Box &B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() {
        return (long long) l * (long long) b * (long long) h;
    }

    bool operator<(Box& b) {
        if (this->l < b.l) {
            return true;
        }
        else if (this->b < b.b) {
            if (this->l == b.l) {
                return true;
            }
        }
        else if (this->h < b.h) {
            if (this->l == b.l && this->b == b.b) {
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& out, Box& b) {
        cout << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
        return out;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}