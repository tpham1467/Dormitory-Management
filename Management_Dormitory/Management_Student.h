#pragma once
#include"Student.h"
#include"Doubly_Linked_List.h"
#include"Khoi_tao.h"
class Management_Student
{
private:
	Doubly_Linked_List<Student> Database;
public:
	Management_Student();
	~Management_Student();
	// Thêm Sinh Viên Vào Cơ Sở Dữ liệu
	void Add_Student(const Student&);
	// Xóa Sinh Viên Ra Khỏi Cơ Sở Dữ Liệu
	void Delete_Student(Student& _student);
	// Tìm Kiếm Sinh Viên
	Doubly_Linked_List<Student> Find_Student(string);
	// Thay Đổi Sinh Viên Mới
	void Update_DataBase(Node<Student>*);
	// Lấy Danh Sách Sinh Viên
	Doubly_Linked_List<Student>& Get_List_Student();
	// Trả Về Con Trỏ Đang Trỏ Tới Sinh Viên
	Node<Student> *Index_off(string);
	// Chuyển Phòng Cho Sinh Viên
	Node<Student>* Move_Room();
	// Ghi Dữ lIệu Ra File 
	void Write_File();
	// Đọc Dữ Liệu Từ File
	void Read_File();
	// Xuất File Excel
	void Export_File_Excel();
	// Menu Để Chọn Chức Nẵng
	void Menu_Student(bool=true);
	// Hàm Vẽ Một Trang Danh Sách Sinh Viên
	void Draw_a_Page(int , int , Doubly_Linked_List<Student>&, int);
	// Hàm Bắt Sự Kiện Bàn Phím Để Điều Hướng Sử dụng Các Chức Năng
	int Move_Page(Doubly_Linked_List<Student>& , bool& , bool&);
	// Hàm Đổi Màu Sinh Viên Đang Chọn
	void Draw_Object(Doubly_Linked_List<Student>&, int, int, int);
	// Hàm Hiển Thị Thông Tin Sinh Viên Được Chọn
	void Draw_Info_Object();
	// hàm Điều Hướng Để Cập Nhập Thông Tin Cho Sinh Viên
	void Update();
	// Hàm Update Thông Tin chỉ Định
	void Updata_Info(int);
	// Hàm Đổi màu Thông tin được chọn
	void Doi_Mau(int,int);
};



