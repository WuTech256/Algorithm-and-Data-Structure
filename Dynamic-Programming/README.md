# Khái niệm cơ bản về Quy hoạch động:
Quy hoạch động giúp giải quyết các vấn đề bằng cách kết hợp các solution cho các bài toán con.
Nó cũng tương tự như phương pháp chia để trị:

## Khác biệt cơ bản giữa Chia để trị và Quy hoạch động

D1:
    + Với chia để trị -> ta chia bài toán lớn thành các bài toán con không giao nhau (Các bài toán con được giải quyết đệ quy và sau đó kết hợp để tìm ra giải pháp cho bài toán ban đầu)
    + Với quy hoạch động -> áp dụng khi các bài toán con chồng chéo, tức các bài toán con sẽ tác động lên các bài toán con khác.

D2: 
    + Chia để trị thực hiện nhiều công việc hơn mức cần thiết, giải quyết nhiều lần các bài toán con (có cùng cách giải với bài toán con khác)
    + Quy hoạch động giải quyết mỗi bài toán con chỉ 1 lần và sau đó lưu cẩu trả lời của bài toán đó vào 1 bảng, nếu có bài toán con khác có liên quan đến bài toán con này sẽ sử dụng kết quả này luôn thay vì tính toán lại -> Do đó tránh công việc tính toán nhiều lần


## DP Solution
    - Có 2 kĩ thuật để giải quyết bài toán DP (Quy hoạch động)
        + Iterative (sử dụng for-cycle) 
            Eg: dp[i] = dp[i-1] + 1;
        + Recursive (Đệ quy)

    - So sánh 2 phương pháp này:
        + Iterative nhanh hơn Recursive
        + Xác định độ phức tạp về space và time dễ dàng hơn.
        + Source code ngắn và clean
    
    - Chúng ta có thể tiếp cận 2 phương pháp trên theo 1 cách dễ hình dung hơn
        + Iterative (Bottom Up) -> Tiếp cận từ dưới lên
        + Recursion (Top-Down) -> Tiếp cận từ trên xuống



    


