
#include <iostream>
using namespace std;
class Room
{
private:
    int length;
    int width;
    int height;

public:
    Room(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    void Area()
    {
        cout << "\nThe Surface Area of the room is " << 2*(length * width + width*height + height*length );
    }
    void Volume()
    {
        cout << "\nThe Volume of the room is " << length * width * height;
    }
};
class NoteCalculator {
private:
    int amount;
public:
    NoteCalculator() {
        amount = 0;
    }
    void inputAmount() {
        cout << "\nEnter the amount: ";
        cin >> amount;
    }

    void Denominations() {
        int denominations[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
        int nCount[9] = { 0 };

        int rAmount = amount;

        for (int i = 0; i < 9; i++) {
            nCount[i] = rAmount / denominations[i];
            rAmount %= denominations[i];
        }

        cout << "Denominations:\n";
        for (int i = 0; i < 9; i++) {
            if (nCount[i] > 0) {
                cout << denominations[i] << " : " << nCount[i] << endl;
            }
        }
    }
};



int main()
{
    Room r(69,1,1);
    r.Area();
    r.Volume();
    NoteCalculator calculator;
    calculator.inputAmount();
    calculator.Denominations();
    return 0;
}