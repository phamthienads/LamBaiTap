#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    // Mảng chứa 5 phần thưởng
    std::string prizes[5] = {"Xe đạp", "Máy tính bảng", "Điện thoại", "Tivi", "Máy ảnh"};

    int index;
    std::cout << "Nhập một số nguyên để chọn phần thưởng (0-4): ";
    std::cin >> index;

    try {
        // Kiểm tra xem chỉ số có nằm trong phạm vi hợp lệ không
        if (index < 0 || index >= 5) {
            throw std::out_of_range("Chỉ số ngoài phạm vi!");
        }
        std::cout << "Bạn đã chọn: " << prizes[index] << std::endl;
    } catch (const std::out_of_range& e) {
        // Xử lý lỗi và chọn phần thưởng ngẫu nhiên
        std::cout << e.what() << " Chúng tôi sẽ chọn phần thưởng cho bạn." << std::endl;
        std::srand(time(0));
        int randomIndex = std::rand() % 5;
        std::cout << "Bạn đã nhận được: " << prizes[randomIndex] << std::endl;
    }

    std::cout << "Cảm ơn bạn đã tham gia! Tạm biệt!" << std::endl;

    return 0;
}
