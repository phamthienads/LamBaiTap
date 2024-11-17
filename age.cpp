#include <iostream>
#include <stdexcept>

int main() {
    int age;
    std::cout << "Vui lòng nhập tuổi của bạn: "; // Yêu cầu nhập tuổi
    std::cin >> age;

    try {
        if (age < 13) {
            // Ném ra lỗi nếu tuổi nhỏ hơn 13
            throw std::runtime_error("Bạn phải ít nhất 13 tuổi.");
        }
        // In thông báo nếu tuổi từ 13 trở lên
        std::cout << "Chào mừng! Bạn đủ tuổi để tiếp tục." << std::endl;
    } catch (const std::runtime_error& e) {
        // Bắt lỗi được ném ra ở trên
        std::cerr << e.what() << std::endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    return 0; // Thoát chương trình thành công
}
