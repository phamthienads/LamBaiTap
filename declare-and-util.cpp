#include <iostream>
using namespace std;

int main() {
    int userScore = 30;      // Khai báo biến userScore
    int& scoreRef = userScore; // Tạo biến tham chiếu scoreRef tham chiếu đến userScore
    // & là toán tử tham chiếu

    // Hiển thị giá trị ban đầu
    cout << "userScore = " << userScore << ", scoreRef = " << scoreRef << endl;

    // Thay đổi giá trị thông qua scoreRef
    scoreRef = 145;

    // Hiển thị giá trị sau khi thay đổi
    cout << "userScore = " << userScore << ", scoreRef = " << scoreRef << endl;

    return 0;
}