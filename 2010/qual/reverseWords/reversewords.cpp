#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct node {
  char* word;
  node* prev;
  node* next;
} Node;

class deque {
  Node* head;
  Node* tail;

 public:
  deque();
  void append(char*);
  char* pop();
}

deque::deque() {
  head = nullptr;
  tail = nullptr;
}

void deque::append(char* w) {
  Node* current = (Node *) malloc(sizeof(Node));
  current->word = w;

  if (head == nullptr) {
    head = current;
    head->prev = nullptr;
    tail = head;
  } else {
    tail->next = current;
    current->prev = tail;
    current->next = nullptr;
    tail = current;
  }
}

char* deque::pop() {
  char* tmp = tail->word;
  if (tail->prev != nullptr) {
    tail = tail->prev;
  } else {
    tail = nullptr;
  }
  return tmp;
}

string reverse(const char* buffer, int length ) {
  ostringstream oss;
  int start = 0;
  Stack* head, top;
  head = nullptr;

  for (int i = 0; i < length; i++) {
    if (*(buffer + i) != ' ') {
      continue;
    }

    char *word = (char *) malloc(i - start + 1);
    strcpy(word, (buffer + start));
    *(word + (stop - start)) = '\0';
    start = i + 1;

    Stack* current = malloc(sizeof(Stack));
    current->word = word;

    if (head == nullptr) {
      head = current;
      top = current;
    } else {
      top->next = current;
      top = current;
    }
  }
  char* word = (char *) malloc(length - start + 1);

//    if (stop == start) {
//      cout << "blank in the beginning\n";
//      continue;
//    }
/*    char* tmp = stop - 1;
    while (tmp != start) {
      oss << *tmp;
      tmp--;
    }
    if (*stop == '\0') {
      break;
    }
    start = stop + 1;
    stop = start; */
  }
  return oss.str();
}

int main() {
  ifstream ifs("B-small-practice.in");
  ofstream ofs("B-small-solution");
  char* buffer = new char[2000];
  ifs.getline(buffer, 2000);
  int numTestCases = stoi(buffer, nullptr);
  for (int test = 0; test <  numTestCases; test++) {
    ifs.getline(buffer, 2000);
    string reversed_string = reverse(buffer, ifs.gcount() - 1);
    ofs << reversed_string << '\n';
  }
  ifs.close();
  ofs.close();
  free(buffer);
}
