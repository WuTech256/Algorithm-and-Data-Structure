# Topological Sorting:
	

	- Topological Sort là kiểu sắp xếp thứ tự các nút của biểu đồ có hướng sao cho nếu có đường dẫn từ nút A đến nút B, thì nút A xuất hiện trước nút B
	theo thứ tự. 

	- Một đồ thị Acyclic (ko có chu trình) luôn luôn tồn tại Topological sort. Tuy nhiên nếu đồ thị tồn tại chu kì, không thể tồn tại Topological Sort,
	bởi vì không có nút nào của chu kì có thể xuất hiện trước các nút còn lại của chu kỳ đó theo thứ tự. 
	Nó chỉ ra rằng DFS có thể được sử dụng để check xem đồ thị có hướng có tồn tại chu kì hay không, và nếu không có chu kì thì hoàn toàn có thể thực hiện Topological Sort.

# Algorithm
	Ý tưởng là đi qua tất cả các nút của đồ thị và luôn luôn bắt đầu với nút hiện tại với DFS nếu nó chưa từng được xử lý. 
	Trong suốt quá trình tìm kiếm, các nút tồn tại ở 3 trạng thái.
		-> state 0: các nút chưa được xử lý
		-> state 1: các nút đang được xử lý
		-> state 3: các nút dã được xử lý
	
	Ban đầu, trạng thái của mỗi nút là 0. Khi một tìm kiếm đến mỗi nút lần đầu tiên, trạng thái của nó trở thành 1. Cuối cùng, sau khi tất cả những nút kế thừa của nút đã được xử lý, trạng
	thái của nó sẽ chuyển thành 2.

