# Advanced_Scheduler
## Mô tả
Dự án này tập trung vào việc mở rộng và sửa đổi bộ lập lịch trong hệ điều hành pintos để xử lý các chức năng như:
- Quản lý ưu tiên luồng (thread priority)
- Hỗ trợ luồng nhường CPU khi cần thiết (priority donation)
- Hỗ trợ hệ thống lập lịch với hàng đợi đa mức phản hồi (MLFQS - Multi-Level Feedback Queue Scheduler)
## Các yêu cầu đã thực hiện
- Priority Scheduling:
    - Thêm thuộc tính 'priority' vào luồng
    - Thay đổi bộ lập lịch (scheduler) để luôn chọn luồng có độ ưu tiên cao nhất để thực thi
    - Khi một luồng mới cao ưu tiên hơn được tạo, nó có thể chiếm CPU.
- MLFQS (Multi-Level Feedback Queue Scheduler):
    - Thêm các biến 'nice', 'recent_cpu' và 'load_avg'
    - Tính toán lại độ ưu tiên theo thời gian: 'priority'= PRI_MAX - (recent_cpu / 4) - (nice * 2)
    - Cập nhâtj 'recent_cpu' và 'load_avg' mỗi giây và mỗi tick
## Những thay đổi với thiết kế ban đầu
* Thêm trường mới vào 'struct thread' trong 'threads/thread.h : 
    - 'int nice'
    - 'int recent_cpu'
* Thêm file 'fixed-point.h' vào 'src/threads' để hỗ trợ phép toán số thực
* Dùng trong MLFQS để tính toán: 'load_avg', 'recent_cpu', 'priority'
* Tạo các hàm cập nhât **mlfqs_update_priority**, **mlfqs_update_recent_cpu**, **mlfqs_update_load_avg** vào 'threads/thread.c'
* Khai báo biến toàn cục **load_avg** trong 'thead.c'
* Hàm timer_interrupt trong 'devices/timer.c' :
    - Mỗi tick: recent_cpu của thread đang chạy tăng 1
    - Mỗi 1 giây (TIMER_FREQ tick): tính lại **load_avg** và cập nhật **recent_cpu** cho tất cả thread
    - Mỗi 4 tick: cập nhật lại priority cho tất cả thread

## Build và chạy 
cd src/threads/build
make clean
make check
