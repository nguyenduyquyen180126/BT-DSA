# Bài tập DSA (ET2040)
Trong repo gồm có bài tập về nhà của môn **Cấu trúc dữ liệu và giải thuật**
## Bài tập tuần 3
Học cách debug một chương trình.
## Bài tập chương mảng 
Cài đặt các thuật toán sắp xếp cơ bản.
- Sắp xếp lựa chộn
- Sắp xếp chèn
- Sắp xếp nổi bọt
## Bài tập tuần 6
Cài đặt 2 thuật toán sắp xếp nâng cao.
- Sắp xếp nhanh
- Sắp xếp trộn
### Cách chạy file test: Trong dir có test_vector.txt chứa các test case, expected.txt chứa các output đúng của các test case trong test_vector.txt (thep đúng thứ tự).
1. Change dir vào bài tập tuần 6:
`cd bai_tap_tuan_6`
2. Khoá các file .a cũ:
`make clean`
3. Chạy test_merge_sort_.c:
`make test_merge_sort`
4. Chạy test_quick_sort.c:
`make test_quick_sort`
## Bài tập tuần 9
Cài đặt các phương thức sau để quản lý danh sách sinh viên với các thuộc tính cần quản lý là Họ tên, MSSV, Năm sinh, Điểm GPA 
- Khai báo danh sách.
- Thực hiện in danh sách thông tin sinh viên. 
- Tính chiều dài của danh sách.
- Tìm số lượng sinh viên có GPA >3.2.
- Sắp xếp danh sách sinh viên theo thứ tự tăng dần của điểm GPA, thêm vào danh sách một sinh viên mới có sinh viên là 2.4 và bổ sung vào danh sách theo thứ tự đúng.