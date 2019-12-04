Checker + generate tests auto

## Hướng dẫn sử dụng ##

Giải nén file CHECKER + GENTEST.rar, được hai thư mục CHECKER (checker), GENTEST (sinh test).

#### Checker: ####

1. Copy file get_logs.exe vào thư mục chứa bài làm
2. Copy file thực thi (.exe) gentest, code trâu, code cần kiểm tra vào thư mục chứa bài làm
3. Thêm file INPUT.log (nếu nhập cài đặt từ file). Các mục trong file INPUT như sau:


            checker (file gentest) (1)
            plus (file code trâu) (2)
            plus_out (file code cần kiểm tra) (3)
            10 (số lượng test kiểm tra) (4)
            0.1 (giới hạn thời gian chạy) (5)

<br><br>Chú ý, (1), (2), (3) không ghi phần đuôi .exe

4. Chạy file get_logs.exe, trong câu hỏi 

            "Nhap tu file? (Y (khuyen dung) / N) "

nhập Y, nhấn Enter (bạn có thể nhập N nhưng phải điền lại tất cả các thông tin trên vào bước 3. Chú ý:
            
            file input là (2).inp
            file out (code trâu) là (2).out
            file out (code cần kiểm tra) là (3).out

5. Trong câu hỏi  

            "Ban co muon giu lai bo test kiem tra? (Y/N)" 

nhập Y để chương trình tạo bộ test (test được tạo sẽ được chứa tại thư mục 

            Test.../(2).inp
            Test.../(2).out 

ngay trong thư mục bài làm

#### Sinh test: ####

1. Copy file generate_test.exe vào thư mục chứa bài làm
2. Copy file thực thi (.exe) gentest, code sinh output (chuẩn) vào thư mục chứa bài làm
3. Chạy file generate_test.exe, nhập các thông tin file:

              Nhap ten file gen (khong ghi .exe): Tên file gen (1)
              Nhap ten file solution: Tên file sinh output (2)
              Nhap so test: Số test cần sinh (3)
              Header: Tên file inp, out (4)
              From: Đánh số kể từ ... (5)
              
<br><br>Chú ý, (1), (2) không ghi phần đuôi .exe

4. Test được tạo sẽ được chứa tại thư mục 

              Test.../(4).inp
              Test.../(4).out 
ngay trong thư mục bài làm

# Console #
## Gen test ##
                Copy file gen test, file solution (duoi .exe) tu bin\Debug\ vao thu muc bai lam!

                Thoi gian nghi giua cac lan sinh bo test: 1.3s

                Nhap ten file gen (khong ghi .exe): checker
                Nhap ten file solution: plus
                Nhap so test: 10
                Header: PLUS
                From: 01
                        1 file(s) copied.
                        1 file(s) copied.

                10%
                        1 file(s) copied.
                        1 file(s) copied.

                20%
                        1 file(s) copied.
                        1 file(s) copied.

                30%
                        1 file(s) copied.
                        1 file(s) copied.

                40%
                        1 file(s) copied.
                        1 file(s) copied.

                50%
                        1 file(s) copied.
                        1 file(s) copied.

                60%
                        1 file(s) copied.
                        1 file(s) copied.

                70%
                        1 file(s) copied.
                        1 file(s) copied.

                80%
                        1 file(s) copied.
                        1 file(s) copied.

                90%
                        1 file(s) copied.
                        1 file(s) copied.

                100%


                DONE!
                DHTCN 2020
                Press any key to continue . . .
## Checker (nhập từ file) ##

                Copy file gen test code trau, code kiem tra (duoi .exe) vao thu muc bai lam!
                Thoi gian nghi giua moi lan sinh test la 1.3s

                Nhap tu file? (Y (khuyen dung)/N) Y


                Nhap theo thu tu sau (moi ten mot dong) trong file INPUT.log (khong ghi .exe voi
                 file gen va code):
                Ten file gen;
                Ten code trau;
                Ten code kiem tra;
                So test;
                Thoi gian chay;



                Bat dau nhap tu file (nhan phim bat ky de chay)
                Press any key to continue . . .


                Ban co muon giu lai bo test kiem tra? (Y/N) Y
                Header: PLUS
                From: 01
                TEST 1:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                10%
                TEST 2:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                20%
                TEST 3:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                30%
                TEST 4:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                40%
                TEST 5:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                50%
                TEST 6:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                60%
                TEST 7:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                70%
                TEST 8:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                80%
                TEST 9:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                90%
                TEST 10:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                100%


                All correct!
                DHTCN 2020
                Press any key to continue . . .

## Checker (không nhập từ file) ##
                Copy file gen test code trau, code kiem tra (duoi .exe) vao thu muc bai lam!
                Thoi gian nghi giua moi lan sinh test la 1.3s

                Nhap tu file? (Y (khuyen dung)/N) N
                Nhap ten file gen (khong ghi .exe): checker
                Nhap ten file code trau (khong ghi .exe): plus
                Nhap ten file code kiem tra (khong ghi .exe): plus_out
                File input: plus.inp;
                File output (code trau): plus.out;
                File output (code kiem tra): plus_out.out;
                Nhap so test: 10
                Nhap gioi han thoi gian chay (VD: 1.25): 0.1
                Ban co muon giu lai bo test kiem tra? (Y/N) Y
                Header: PLUS
                From: 01
                TEST 1:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                10%
                TEST 2:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                20%
                TEST 3:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                30%
                TEST 4:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                40%
                TEST 5:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                50%
                TEST 6:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                60%
                TEST 7:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                70%
                TEST 8:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                80%
                TEST 9:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                90%
                TEST 10:         1 file(s) copied.
                Comparing files PLUS_out.out and PLUS.OUT
                FC: no differences encountered

                        1 file(s) copied.
                CORRECT

                100%


                All correct!
                DHTCN 2020
                Press any key to continue . . .
                
Code by DH_TCN (2020)
