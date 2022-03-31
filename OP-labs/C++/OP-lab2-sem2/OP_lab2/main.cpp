#include "header.h"

/*Створити файл із списком клієнтів, обслужених менеджером протягом дня :
  прізвище, час приходу та час закінчення обслуговування. При введенні
  даних перевіряти їхню допустимість (чи не перетинаються клієнти з наявними). 
  Створити новий файл, який містить інформацію про клієнтів,
  з якими менеджер спілкувався понад 30 хв.*/

int main() {
	const char* FName1 = "abc.dat";
	const char* FName2 = "dce.dat";
	CreateFile(FName1);
	cout << FName1 << ":\n";
	PrintFile(FName1);
	CreateNewFile(FName1, FName2);
	cout << FName2 << ":\n";
	PrintFile(FName2);
}