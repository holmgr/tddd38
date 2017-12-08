#include <iostream>
#include <set>
#include <iterator>
#include <utility>
#include <stdexcept>

using namespace std;

template<typename Key, typename Compare = less<Key>, typename Allocator = allocator<Key>>
class indexable_set : public set<Key, Compare, Allocator>
{
public:
    using set<Key, Compare, Allocator>::set;
    ~indexable_set () = default;

    using set_type = set<Key, Compare, Allocator>;
    using size_type = typename set_type::size_type;

    Key const & operator[](size_type pos) {
        if (pos < 0 || pos >= set_type::size()) {
           throw out_of_range("Index out of bounds");
        }
        auto it = set_type::begin();
        advance(it, pos);
        return *it;
    }

    Key const & at(size_type pos) {
        return this[pos];
    }

private:
    /* data */
};


int main()
{
   using ix_set = indexable_set<int>;

   ix_set ixs0;
   cout << "A default initialized indexable_set have size " << ixs0.size() << ".\n\n";
   

   ix_set ixs{ 3, 8, 2, 5, 1, 4, 7, 6, 9 };

   cout << "This indexable_set have size " << ixs.size() << ", and contains:\n";
   for (auto x : ixs)
      cout << x << ' ';
   cout << "\n\n";

   for (auto i : { 0, 3, 8, 2, 5, 1, 4, 7, 6, 9, -1 })
   {
      try
      {
	 auto x = ixs[i];
	 cout << "element at index " << i << " is " << x << '\n';
      }
      catch (const exception& e)
      {
	 cout << e.what() << ": " << i << " is not a valid index\n";
      }
   }
   cout << '\n';

   ix_set::iterator   it = ixs.begin();
   ix_set::value_type x = *it;

   cout << "First element in the indexable_set above is: " << x << "\n\n";

   ix_set ixs2{ixs};
   cout << "Copied-from indexable_set is empty? " << boolalpha << ixs.empty() << '\n';
   cout << "New copies-to indexable_set have size " << ixs2.size() << "\n\n";

   ix_set ixs3{std::move(ixs)};
   cout << "Moved-from indexable_set is empty? " << ixs.empty() << '\n';
   cout << "New moved-to indexable_set have size " << ixs3.size() << "\n\n";

   ixs = ixs2;
   cout << "Copy-assigned-from indexable_set is empty? " << ixs2.empty() << '\n';
   cout << "Copy-assigned-to indexable_set have size " << ixs.size() << "\n\n";

   ixs2 = std::move(ixs3);
   cout << "Move-assigned-from indexable_set is empty? " << ixs3.empty() << '\n';
   cout << "Moved-assigned-to indexable_set have size " << ixs2.size() << "\n\n";

   ixs3 = { 22, 33, 11 };
   for (auto x : ixs3)
      cout << x << ' ';
   cout << "\n\n";

   return 0;
}

