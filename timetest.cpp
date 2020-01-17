#include <iostream>
#include "CursorList.cpp"
#include "LinkedList.cpp"
#include "QueueAr.cpp"
#include "QueueLL.cpp"
#include "SkipList.cpp"
#include "StackAr.cpp"
#include "StackLi.cpp"
#include "vector.cpp"
#include <fstream>
#include "CPUTimer.h"
vector<CursorNode <int> > cursorSpace(500001);


int getChoice() {
  int choice;
  std::cout << "ADT Menu:" << std::endl;
  std::cout << "0. Quit\n"
               "1. LinkedList\n"
               "2. CursorList\n"
               "3. StackAr\n"
               "4. StackLi\n"
               "5. QueueAr\n"
               "6. SkipList\n"
               "Your choice >> ";
  std::cin >> choice;
  std::cin.ignore(256, '\n');
  return choice;
}

std::ifstream readFile(char* fileName) {
  std::ifstream file(fileName);
  file.ignore(500, '\n');
  return file;
}
void RunList(char* fileName) {
  List<int> list;
  std::ifstream file = readFile(fileName);
  char entries;
  int value;
  while (file >> entries >> value) {
    if (entries == 'i') {
      list.insert(value,list.zeroth());
    } else if (entries == 'd') {
      list.remove(value);
    }
  }

}

void RunCursorList(char* fileName) {
  CursorList<int> cursor_list(cursorSpace);
  std::ifstream file = readFile(fileName);
  char entries;
  int value;
  while (file >> entries >> value) {
    if (entries == 'i') {
      cursor_list.insert(value,cursor_list.zeroth());
    } else if (entries == 'd') {
      cursor_list.remove(value);
    }
  }

}

void RunQueueAr(char* fileName) {
  Queue<int> queue_ar(500001);
  std::ifstream file = readFile(fileName);
  char entries;
  int value;
  while (file >> entries >> value) {
    if(entries == 'i'){
      queue_ar.enqueue(value);
    }
    else if (entries == 'd'){
      queue_ar.dequeue();
    }
  }
}

void RunStackAr(char* fileName) {
  StackAr<int> stack_ar(500001);
  std::ifstream file = readFile(fileName);
  char entries;
  int value;
  while (file >> entries >> value) {
    if(entries == 'i'){
      stack_ar.push(value);
    }
    else if (entries == 'd'){
      stack_ar.pop();
    }
  }

}

void RunStackLi(char* fileName) {
  StackLi<int> stack_li;
  std::ifstream file = readFile(fileName);
  char entries;
  int value;
  while (file >> entries >> value) {
    if (entries == 'i') {
      stack_li.push(value);
    } else if (entries == 'd') {
      stack_li.pop();
    }
  }
}

void RunSkipList(char* fileName) {
  char entries;
  int value;
  SkipList<int> skip_list(0, 500001);
  std::ifstream file = readFile(fileName);
  while (file >> entries >> value) {
    if (entries == 'i') {
      skip_list.insert(value);
    } else if (entries == 'd') {
      skip_list.deleteNode(value);
    }
  }
}


int main(int argc, char** argv) {
//C:/Users/T PC/Desktop/ECS 036C HW1/File1.dat
  char fileName[80];
  std::cout << "Filename >> ";
  std::cin.getline (fileName, 80);
  CPUTimer ct;
  int choice;
  do {
    choice = getChoice();
    ct.reset();
    switch(choice) {
      case 1: RunList(fileName);
        break;
      case 2: RunCursorList(fileName);
        break;
      case 3: RunStackAr(fileName);
        break;
      case 4: RunStackLi(fileName);
        break;
      case 5: RunQueueAr(fileName);
        break;
      case 6: RunSkipList(fileName);
        break;
      default:
        std::cout << "Enter a number from 0-6" << std::endl;
        break;
    }
    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while (choice > 0);
  return 0;
}
