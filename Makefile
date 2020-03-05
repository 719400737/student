objects=CStudent.o main.o CStudentMg.o CMainView.o 
stu:$(objects)
	g++ $(objects) -o stu
main.o:CStudent.h CStudentMg.h CMainView.h
CStudentMg.o:CStudent.h
CMainView.o:CStudent.h CStudentMg.h
.PHONY:clean
clean:
	-rmedit $(objects)