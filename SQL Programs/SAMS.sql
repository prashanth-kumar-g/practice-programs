CREATE DATABASE SAMS;

USE SAMS;

CREATE TABLE admin_table (
	Admin_Id   VARCHAR(50)   PRIMARY KEY,
	Name       VARCHAR(100)  NOT NULL,
	Password   VARCHAR(50)   NOT NULL,
	Mobile_No  NUMERIC(10,0) NOT NULL,
	Address    VARCHAR(250)  NOT NULL,
    Photo      VARCHAR(150)  NOT NULL
);

CREATE TABLE student_table (
	Student_Id VARCHAR(50)   PRIMARY KEY,
	Name       VARCHAR(100)  NOT NULL,
	Photo      VARCHAR(150)  NOT NULL,
	Gender     VARCHAR(15)   NOT NULL,
	Course     VARCHAR(10)   NOT NULL,
    Class      VARCHAR(10)   NOT NULL,
    Mobile_No  NUMERIC(10,0) NOT NULL,
    Address    VARCHAR(250)  NOT NULL
);

CREATE TABLE attendance_table (
    Student_Id  VARCHAR(50),
    Date        VARCHAR(10),
    Attendance  VARCHAR(10) NOT NULL,
    PRIMARY KEY (Student_Id, Date),
    FOREIGN KEY (Student_Id) 
		REFERENCES student_table(Student_Id) 
		ON DELETE CASCADE
);

CREATE TABLE overall_attendance_table (
    Student_Id      VARCHAR(50)   PRIMARY KEY,
    Name            VARCHAR(100)  NOT NULL,
    Course          VARCHAR(10)   NOT NULL,
    Class           VARCHAR(10)   NOT NULL,
    Total_Classes   NUMERIC(3,0)  NOT NULL,
    Classes_Attended NUMERIC(3,0) NOT NULL,
    Percentage      VARCHAR(10)   NOT NULL,
    FOREIGN KEY (Student_Id) 
		REFERENCES student_table(Student_Id) 
        ON DELETE CASCADE
);

USE SAMS;

SELECT * FROM admin_table;
SELECT * FROM student_table;
SELECT * FROM attendance_table;
SELECT * FROM overall_attendance_table;

TRUNCATE TABLE admin_table;
DELETE FROM student_table;
TRUNCATE TABLE attendance_table;
TRUNCATE TABLE overall_attendance_table;

USE SAMS;

EXEC sp_help admin_table;
EXEC sp_help student_table;
EXEC sp_help attendance_table;
EXEC sp_help overall_attendance_table;

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo)
	VALUES ('prash123', 'Prashanth Kumar G', 'Pra12#!G', 7406921907, 'Bangalore', 'Images\prashanth.jpg');

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo)
    VALUES ('admin', 'Administrator', 'admin123', 1010101010, 'Computer', 'Images\admin.jpeg');

DELETE FROM admin_table WHERE Admin_Id='prash123';

DELETE FROM attendance_table WHERE Date = '20-05-2025';

SELECT COUNT(*) FROM attendance_table;

UPDATE admin_table SET Photo = 'Images\' + RIGHT(Photo, CHARINDEX('\', REVERSE(Photo)) - 1);

UPDATE student_table SET Photo = 'Images\' + RIGHT(Photo, CHARINDEX('\', REVERSE(Photo)) - 1);

sp_who2;
CREATE NONCLUSTERED INDEX idx_attendance_student_date ON attendance_table(Student_Id, Date);
SELECT name, type_desc FROM sys.indexes WHERE object_id = OBJECT_ID('attendance_table');
ALTER DATABASE SAMS SET READ_COMMITTED_SNAPSHOT ON;

BACKUP DATABASE [master] TO DISK = 'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS02\MSSQL\Backup\master.bak' WITH INIT;
BACKUP DATABASE [msdb] TO DISK = 'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS02\MSSQL\Backup\msdb.bak' WITH INIT;
BACKUP DATABASE [model] TO DISK = 'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS02\MSSQL\Backup\model.bak' WITH INIT;
BACKUP DATABASE [SAMS] TO DISK = 'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS02\MSSQL\Backup\SAMS.bak' WITH INIT;

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo) VALUES ('ashok345', 'Ashok Gowda', 'Ash12#!G', '9480685964', 'Bangalore', 'Images\ashok.jpg');

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo) VALUES ('meena678', 'Meena Iyer', 'Mee12#!G', '7204869787', 'Bangalore', 'Images\meena.jpeg');

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo) VALUES ('prash123', 'Prashanth Kumar G', 'Pra12#!G', '7406921907', 'Bangalore', 'Images\prashanth.jpg');

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo) VALUES ('principal111', 'Principal', 'Pri12#!G', '8068248454', 'Bangalore', 'Images\principal.jpg');

INSERT INTO admin_table (Admin_Id, Name, Password, Mobile_No, Address, Photo) VALUES ('test000', 'Test', 'Tes12#!G', '9019915817', 'Bangalore', 'Images\test.jpg');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012578', 'Abhishek C', 'Images\abhishek.jpg', 'Male', 'BCA', '5th Sem', '7760504651', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012579', 'Divya Sharma', 'Images\divya.jpeg', 'Female', 'BCA', '5th Sem', '8025735642', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012580', 'Sahil Shah', 'Images\sahil.jpeg', 'Male', 'BCA', '5th Sem', '9480683707', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012581', 'Sneha Nair', 'Images\sneha.jpg', 'Female', 'BCA', '5th Sem', '8242218816', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012582', 'Prashanth Kumar G', 'Images\prashanth.jpg', 'Male', 'BCA', '5th Sem', '7406921907', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012583', 'Raj Verma', 'Images\raj.jpeg', 'Male', 'BCA', '5th Sem', '9480683650', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012584', 'Amisha Patel', 'Images\amisha.jpg', 'Female', 'BCA', '5th Sem', '8023636671', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012585', 'Pavan Shetty', 'Images\pavan.jpg', 'Male', 'BCA', '5th Sem', '9380206704', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012586', 'Nandini V K', 'Images\nandini.jpg', 'Female', 'BCA', '5th Sem', '7760990034', 'Bangalore');

INSERT INTO student_table (Student_Id, Name, Photo, Gender, Course, Class, Mobile_No, Address)
VALUES ('R2012587', 'Rahul Singh', 'Images\rahul.jpg', 'Male', 'BCA', '5th Sem', '9741388123', 'Bangalore');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '14-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '14-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '14-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '14-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '14-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '15-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '15-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '15-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '15-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '16-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '16-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '16-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '17-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '17-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '17-06-2025', 'Absent');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '18-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '18-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '18-06-2025', 'Absent');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '19-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '19-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '19-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '19-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '20-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '20-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '20-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '21-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '21-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '21-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '21-06-2025', 'Present');

INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012578', '22-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012579', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012580', '22-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012581', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012582', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012583', '22-06-2025', 'Absent');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012584', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012585', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012586', '22-06-2025', 'Present');
INSERT INTO attendance_table (Student_Id, Date, Attendance) VALUES ('R2012587', '22-06-2025', 'Absent');
