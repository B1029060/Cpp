#include <iostream>
using namespace std;

// ADT
struct NaturalNumber {
    int Zero() {
        return 0;
    }
    bool IsZero(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        } else {
            return false;
        }
    }
    int Add(int x, int y) {
        if (x < 0 || y < 0) {
            return -1;
        } else if (INT_MAX - x < y) {
            return INT_MAX;
        } else {
            return x + y;
        }
    }
    bool Equal(int x, int y) {
        if (x < 0 || y < 0) {
            return false;
        }
        if (x == y) {
            return true;
        } else {
            return false;
        }
    }
    int Successor(int x) {
        if (x < 0) {
            return -1;
        }
        if (x == INT_MAX) {
            return INT_MAX;
        } else {
            return x + 1;
        }
    }
    int Substract(int x, int y) {
        if (x < 0 || y < 0) {
            return -1;
        }
        if (x < y) {
            return 0;
        } else {
            return x - y;
        }
    }
    // Exercise 1 - Add operations Predecessor, IsGreater, Multiply, Divide to the NaturalNumber ADT.
    int Predecessor(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        } else {
            return x - 1;
        }
    }
    bool IsGreater(int x, int y) {
        if (x < 0 || y < 0) {
            return false;
        } else if (x > y) {
            return true;
        } else {
            return false;
        }
    }
    int Multiply(int x, int y) {
        if (x < 0 || y < 0) {
            return -1;
        } else if (x == 0 || y == 0) {
            return 0;
        } else if (INT_MAX / x >= y) {
            return x * y;
        } else {
            return INT_MAX;
        }
    }
    int Divide(int x, int y) {
        if (x < 0 || y < 0) {
            return -1;
        } else if (y == 0) {
            return -1;
        } else {
            return x / y;
        }
    }
    
};

/*  Exercise 2 - Create an ADT, Set. Use the standard mathematical definition and include the following operations: 
    Create, Insert, Remove, IsIn, Union, Intersection, Difference.
*/
struct Set {
    int set[1001] {0};
    void Create() {
        for (int i = 0; i <= 1000; i++) {
            set[i] = 0;
        }
    }
    void Insert(int x) {
        if (0 <= x && x <= 1000) {
            set[x] = 1;
        }
    }
    void Remove(int x) {
        if (0 <= x && x <= 1000) {
            set[x] = 0;
        }
    }
    bool IsIn(Set *s) {
        for (int i = 0; i <= 1000; i++) {
            if (s->set[i] == 0 && set[i] == 1) {
                return false;
            } 
            return true;
        }
    }
    void Union(Set *s) {
        for (int i = 0; i <= 1000; i++) {
            if (s->set[i] == 1) {
                set[i] = 1;
            }
        }
    }
    void Intersection(Set *s) {
        for (int i = 0; i <= 1000; i++) {
            if (s->set[i] == 0 || set[i] == 0) {
                set[i] = 0;
            }
        }
    }
    void Difference(Set *s) {
        for (int i = 0; i <= 1000; i++) {
            if (s->set[i] == 1) {
                set[i] = 0;
            }
        }
    }
    // For visualization of set.
    void print(int start, int end) {
        for (int i = max(0, start); i <= min(1000, end); i++) {
            cout << set[i] << endl;
        }
        cout << "----------  Finish.  ----------" << endl;
    }

};

/*  Exercise 3 - Create an ADT, Bag. In mathematics a bag is similar to a set except that a bag may contain duplicate elements.
    The minimal operations should include Create, Insert, Remove, IsIn, and IsIn.
*/
struct Bag {
    int bag[1001] {0};
    void Create() {
        for (int i = 0; i <= 1000; i++) {
            bag[i] = 0;
        }
    }
    void Insert(int x) {
        if (0 <= x && x <= 1000) {
            bag[x]++;
        }
    }
    void Remove(int x) {
        if (0 <= x && x <= 1000) {
            bag[x] = max(0, bag[x] - 1);
        }
    }
    bool IsIn(Bag *b) {
        for (int i = 0; i <= 1000; i++) {
            if (b->bag[i] == 0 && bag[i] == 1) {
                return false;
            }
            return true;
        }
    }
        
};


int main() {
    // ex.1
    NaturalNumber n;
    cout << n.Zero() << endl;
    cout << n.Multiply(9, 8) << endl;
    cout << "ex.1 finished" << endl;
    // ex.2
    Set s1, s2;
    s1.Create();
    s2.Create();
    s1.Insert(1);
    s1.Insert(2);
    s1.print(0, 5);
    s2.Insert(3);
    s1.Union(&s2);
    s1.print(0, 5);
    cout << s2.IsIn(&s1) << endl;
    cout << "ex.2 finished" << endl;
    // ex.3
    Bag b1, b2;
    b1.Create();
    b2.Create();
    b1.Insert(1);
    b1.Insert(2);
    b2.Insert(2);
    cout << b2.IsIn(&b1) << endl;
    cout << "ex.3 finished" << endl;
    
    return 0;
}
