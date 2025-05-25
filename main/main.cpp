#define BTREE


#ifdef HESH_MAP

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <random>
#include <optional>
#include <iostream>
#include <string>
#include <type_traits>
#include "../lib_HeshMap/HeshMap.h"

int main() {
    Hesh_table<int, int> f;
    Hesh_table<std::string, int> h;
    //   f.insert(34, 55);
    //std::cout<<Hesh_function("ned");
    try {
        h.insert("pol", 55);
        h.insert("ned", 56);
        h.insert("nedo", 58);
        h.print();
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what();
    }
    return 0;
    

}
#endif


#ifdef MAS_UNSORTED
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <random>
#include <optional>
#include "../lib_mas_unsorted/mas_unsorted.h"
int main() {
    sorted<int, int> list;
    try {
        list.insert(5, 4);
        list.insert(7, 8);
        list.insert(6);
        list.remove(5);
        list.remove(7);

        list.print();
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what();
    }
    return 0;

}
#endif



#ifdef LIST_UNSORTED
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <random>
#include <optional>
#include "../lib_list_unsorted/List_unsorted.h"
int main() {
    sorted<int, int> list;
    try {
        list.insert(5,4);
        list.insert(7, 8);
        list.insert(6);
        list.remove(5);
        list.remove(7);
     
        list.print();
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what();
    }
    return 0;

}
#endif

#ifdef BTREE

#include <iostream>
#include "../lib_Btree/Btree.h"

int main() {
    BTreeNode<int>* root = nullptr;
    root = root->insert(root, 1);
    root = root->insert(root, 6);
    root = root->insert(root, 3);
    root = root->insert(root, 4);
    root = root->insert(root, 2);
    root->print(root);
    //root = root->erase(root, 3);
   // root->clear();
    /*try {
        root->print(root);
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what();
    }*/
    return 0;
}
#endif


#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  return 0;
}

#endif  // EASY_EXAMPLE