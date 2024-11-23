#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Nguyên mẫu hàm
void displayPrizes(const string prizes[], int prizeCount);
int calculateScore(int baseScore);

int main() {
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(static_cast<unsigned>(time(0)));

    // Chào người chơi
    string playerName;
    cout << "Chào mừng đến với trò chơi! Tên bạn là gì? ";
    getline(cin, playerName);
    cout << "Xin chào, " << playerName << "! Bắt đầu trò chơi nào!" << endl;

    // Tạo một số ngẫu nhiên
    int randomNumber = rand() % 3 + 1;

    // Câu lệnh switch để xác định kịch bản
    string prize;
    switch (randomNumber) {
        case 1:
            prize = "Cúp Vàng";
            cout << "Bạn đã tìm thấy một Cúp Vàng!" << endl;
            break;
        case 2:
            prize = "Huy Chương Bạc";
            cout << "Bạn đã tìm thấy một Huy Chương Bạc!" << endl;
            break;
        case 3:
            prize = "Huy Hiệu Đồng";
            cout << "Bạn đã tìm thấy một Huy Hiệu Đồng!" << endl;
            break;
        default:
            cout << "Không tìm thấy phần thưởng!" << endl;
            break;
    }

    // Thêm vòng lặp while để chơi lại trò chơi
    char playAgain;
    while (true) {
        cout << "Bạn có muốn chơi lại không? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            cout << "Cảm ơn vì đã chơi, " << playerName << "!" << endl;
            break;
        } else if (playAgain == 'y' || playAgain == 'Y') {
            cout << "Khởi động lại trò chơi..." << endl;
        } else {
            cout << "Nhập không hợp lệ. Vui lòng nhập 'y' hoặc 'n'." << endl;
        }
    }

    // Sử dụng vòng lặp for để hiển thị các phần thưởng đã thu thập
    string prizes[] = {"Cúp Vàng", "Huy Chương Bạc", "Huy Hiệu Đồng"};
    int prizeCount = 3;
    cout << "\nĐây là tất cả các phần thưởng có thể có: " << endl;
    displayPrizes(prizes, prizeCount);

    // Sử dụng hàm để tính điểm
    int baseScore = 100;
    int finalScore = calculateScore(baseScore);
    cout << "Điểm cuối cùng của bạn là: " << finalScore << endl;

    return 0;
}

// Hàm để hiển thị danh sách phần thưởng
void displayPrizes(const string prizes[], int prizeCount) {
    for (int i = 0; i < prizeCount; i++) {
        cout << "- " << prizes[i] << endl;
    }
}

// Hàm để tính điểm cuối cùng
int calculateScore(int baseScore) {
    int multiplier = rand() % 5 + 1; // Hệ số ngẫu nhiên từ 1 đến 5
    return baseScore * multiplier;
}
