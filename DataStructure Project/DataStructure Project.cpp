#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int transfer_disk(stack<int>& a, stack<int>& b) {
    if (b.empty() == true) {
        b.push(a.top());
        a.pop();
        return 1;
    }
    else if (a.empty() == true) {
        a.push(b.top());
        b.pop();
        return 2;
    }
    else {
        if (b.top() > a.top()) {
            b.push(a.top());
            a.pop();
            return 1;
        }
        else {
            a.push(b.top());
            b.pop();
            return 2;
        }
    }
}
int main() {

    stack<int> s, a, d;
    int n = 0;

    cout << "Welcome Eng. Doaa To our Very own Tower of Hanoi Game!" << endl;
    
    cout << "Kindly Enter the Number  of disks" << endl;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        s.push(i);
    }

    int x = pow(2, n) - 1;
    int i = 1;

    if (n % 2 == 0) {
        while (i <= x) {
            if (i % 3 == 1) {
                int y = transfer_disk(s, a);
                if (y == 1) {
                    cout << "Move the disk " << a.top() << " from Tower A to Tower B" << endl;
                }
                else
                    cout << "Move the disk " << s.top() << " from Tower B to Tower A" << endl;
            }
            else if (i % 3 == 2) {
                int y = transfer_disk(s, d);
                if (y == 1) {
                    cout << "Move the disk " << d.top() << " from Tower A to Tower C" << endl;
                }
                else
                    cout << "Move the disk " << s.top() << " from Tower C to Tower A" << endl;
            }
            else {
                int y = transfer_disk(a, d);
                if (y == 1) {
                    cout << "Move the disk " << d.top() << " from Tower B to Tower C" << endl;
                }
                else
                    cout << "Move the disk " << a.top() << " from Tower C to Tower B" << endl;
            }
            i++;
        }
    }
    else {
        while (i <= x) {
            if (i % 3 == 1) {
                int y = transfer_disk(s, d);
                if (y == 1) {
                    cout << "Move the disk " << d.top() << " from Tower A to Tower C" << endl;
                }
                else
                    cout << "Move the disk " << s.top() << " from Tower C to Tower A" << endl;
            }
            else if (i % 3 == 2) {
                int y = transfer_disk(s, a);
                if (y == 1) {
                    cout << "Move the disk " << a.top() << " from Tower A to Tower B" << endl;
                }
                else
                    cout << "Move the disk " << s.top() << " from Tower B to Tower A" << endl;
            }
            else {
                int y = transfer_disk(a, d);
                if (y == 1) {
                    cout << "Move the disk " << d.top() << " from Tower B to Tower C" << endl;
                }
                else
                    cout << "Move the disk " << a.top() << " from Tower C to Tower B" << endl;
            }
            i++;
        }
    }

    while (d.empty() != true) {
        cout << d.top() << endl;
        d.pop();
    }


    return 0;
}