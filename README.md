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
## Bài tập phần Stack
## Bài tập tuần 14 
- Cài đặt cây chỉ mục , tạo 2 project theo 2 cách cài đặt khác nhau 
- Cài đặt cây tương ứng với cấu trúc lưu trữ tuần tự 
- Cài đặt cây tương ứng với cấu trúc lưu trữ móc nối
- Cài đặt các hàm khởi tạo cây, kiểm tra cây rỗng, thêm vào các nút con trái con phải , hàm duyệt cây theo 3 phương thức trước, giữa, sau 
Nhập thông tin các nút trên cây như hình vẽ mô tả trong file đính kèm.
## Bài tập tuần 14-15
- Bài 1: Cài đặt cây nhị phân để dựng được một cây có các nút lưu trữ số nguyên theo cấu trúc dưới đây (có thể lựa chọn cài đặt theo cấu trúc lưu trữ tuần tự hoặc móc nối)
1. In giá trị các nút trên cây nhị phân theo thứ tự duyệt trước, duyệt sau, duyệt giữa
2. Thiết kế và cài đặt giải thuật vun đống cho cây, in ra giá trị các nút trên cây đã được vun đống theo thứ tự duyệt trước
- Bài 2: Thiết kế giải thuật để kiểm tra 2 cây nhị phân có giống hệt nhau hay không
- Bài 3: Hãy cài đặt cấu trúc dữ liệu cây nhị phân tìm kiếm theo khung chương trình cho bên dưới. Mỗi nút trên cây chứa một số nguyên. Cấu trúc dữ liệu này cho phép chèn thêm nút mới và tìm kiếm nút theo một giá trị cho trước
## Bài tập tuần 17
- Bài 1: Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó mỗi node có thể là chapter (chương), section (mục), subsection (mục con), subsubsection (các mục của mục con).
Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa ở mỗi node sinh viên tự đưa vào (Gợi ý: có thể dùng số để đánh index cho các phần) để đảm bảo các nội dung sau được thực hiện:
1. Xác định số chương của cuốn sách
2. Tìm chương dài nhất của cuốn sách
3. Thực hiện tìm một mục và xoá mục đó khỏi sách. Lưu ý cập nhật lại số trang của từng mục.
4. Tìm một chương bất kỳ và in ra đề mục của chương đó.
- Bài 2: Thiết kế giải thuật để kiểm tra hai cuốn sách có phải là bản copy của nhau không (Gợi ý: Mỗi node chưa 2 thuộc tính là index dạng số, và tên mục dạng chuỗi ký tự).
## Bài tập tuần 17 online
Cài đặt cây theo 2 cách