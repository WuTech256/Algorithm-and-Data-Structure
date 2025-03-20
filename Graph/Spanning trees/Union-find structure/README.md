Union-find Structure

Union-find là một cấu trúc để duy trì và quản lý một tập hợp các tập hợp (collection of sets).
Các tập hợp là rời rạc, do đó không có phần tử nào thuộc về nhiều hơn một tập hợp.

# Hai thao tác chính (đều có độ phức tạp O(logn)):
	Unite – Kết hợp hai tập hợp thành một.
	Find – Tìm đại diện của tập hợp chứa một phần tử nhất định.
# Cấu trúc:
	- Trong một cấu trúc union-find, mỗi tập hợp có một phần tử đại diện. Tất cả các phần tử khác trong tập hợp được liên kết trực tiếp hoặc gián tiếp đến phần tử đại diện thông qua một chuỗi liên kết.
	- Khi thực hiện thao tác unite, hai tập hợp được nối bằng cách kết nối đại diện của một tập hợp với đại diện của tập hợp kia.
  - Hiệu quả của cấu trúc union-find phụ thuộc vào cách các tập hợp được nối với nhau.
    Một chiến lược tối ưu là luôn kết nối đại diện của tập hợp nhỏ hơn với đại diện của tập hợp lớn hơn.
		Sử dụng chiến lược này sẽ đảm bảo rằng độ dài của bất kỳ chuỗi liên kết nào là 
		O(logn), cho phép tìm phần tử đại diện một cách hiệu quả.
		
# Triển khai:
	Cấu trúc union-find có thể được triển khai bằng mảng.
	Trong triển khai dưới đây:
	-> Mảng `link[]` chứa phần tử tiếp theo trong chỗi liên kết cho mỗi phần tử, hoặc chính phần tử đó nếu nó là đại diện của tập hợp.
	-> Mảng `size()` chỉ ra kích thước của tập hợp tương ứng cho mỗi phần tử đại diện.
	
	## Khởi tạo
	
		Ban đầu, mỗi phần tử thuộc về một tập hợp riêng biệt:
			for(int i = 1; i <= n; ++i) link[i] = i;
			for(int i = 1; i <= n; ++i) size[i] = i;
			
	## Hàm find()
		
		Hàm find trả về phần tử đại diện cho phần tử `x`
		Phần tử đại diện được bằng cách lần theo chuỗi liên kết bắt đầu từ `x`
		
		int find(int x) {
			while(x != link[x]) x = link[x];
			return x;
		}
	## Hàm same
		Hàm `same` kiểm tra xem hai phần tử a và b có thuộc cùng một tập hợp hay không. 
		Việc này có thể thực hiện dễ dàng bằng cách sử dụng hàm find:
		
		bool same(int a, int b) {
			return find(a) == find(b);
		}
		
		
	## Hàm Unite
		
		Hàm unite kết hợp 2 tập hợp chứa phần tử a và b (2 phần tử này thuộc các tập hợp khác nhau)
		
		void unite(int a, int b) {
			a = find(a);
			b = find(b);
			if(size(a) < size(b)) swap(a, b);
			size[a] += size[b];
			link[b] = a;
		}
		
# Độ phức tạp:
	- Độ phức tạp của hàm find là O(logn) vì chiều dài của mỗi chuỗi liên kết là O(logn).
	- Trong trường hợp này, các hàm `same` và `unite` cũng có độ phức tạp là O(logn).
	- Hàm unite đảm bảo rằng chiều dài của mỗi chuỗi là O(logn) bằng cách nối tập hợp nhỏ hơn vào tập hợp lớn hơn.
