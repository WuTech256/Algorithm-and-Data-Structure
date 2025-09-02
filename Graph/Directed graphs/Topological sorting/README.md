# Topological Sort

## 1. Khái niệm
- **Topological Sort** là cách sắp xếp thứ tự các đỉnh trong **đồ thị có hướng, không chu trình (DAG)** sao cho:
  - Nếu có cạnh từ `A → B`, thì `A` phải xuất hiện **trước** `B` trong kết quả sắp xếp.

- Nếu đồ thị có **chu trình**, thì **không thể** thực hiện Topological Sort, bởi vì trong chu trình không có đỉnh nào có thể đứng trước các đỉnh còn lại.

---

## 2. Ứng dụng
- Lập lịch học phần (môn nào học trước, môn nào học sau).
- Quản lý thứ tự build file khi compile code.
- Xác định thứ tự thực hiện các công việc có phụ thuộc.

---

## 3. Ý tưởng với DFS
Thuật toán DFS được dùng để vừa **phát hiện chu trình**, vừa **tạo thứ tự topo**.

Mỗi đỉnh trong đồ thị có 3 trạng thái:

- **State = 0**: Đỉnh **chưa được xử lý** (chưa thăm).
- **State = 1**: Đỉnh **đang được xử lý** (đang trong ngăn xếp DFS).
- **State = 2**: Đỉnh **đã xử lý xong** (tất cả đỉnh kề đã được duyệt).

### Quy trình:
1. Khởi tạo tất cả các đỉnh với `state = 0`.
2. Với mỗi đỉnh chưa xử lý:
   - Gọi `DFS(u)`.
   - Trong DFS:
     - Đặt `state[u] = 1`.
     - Với mỗi cạnh `u → v`:
       - Nếu `state[v] = 0` → tiếp tục DFS(v).
       - Nếu `state[v] = 1` → phát hiện **chu trình** → **không thể topo**.
     - Sau khi duyệt xong tất cả đỉnh kề, đặt `state[u] = 2` và đưa `u` vào kết quả.
3. Đảo ngược kết quả → thu được thứ tự topo.

---

## 4. Ví dụ
Đồ thị:

