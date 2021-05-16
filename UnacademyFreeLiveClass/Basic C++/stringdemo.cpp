// #include <iostream>
// #include <locale>
// #include <codecvt>
// using namespace std;


// void* operator new(size_t size) {
// 	cout<<"alloc"<<size<<endl;
// 	return malloc(size);
// }

// int main(int argc, char const *argv[])
// {

// 	// using namespace std::string_literals;



// 	// std::string str = "sanket"s + "singh";
// 	// const wchar_t str[] = L"sanket";
// 	// wcout<<str<<endl;;
// 	// std::u16string u16str = u"meu teste";
//  //    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> codecvt;
//  //    std::string u8str = codecvt.to_bytes(u16str);
//  //    std::cout << u8str << '\n';
// 	const char16_t* s = u"sanket";
// 	cout<<((char)s[5])<<endl;
// 	string str = "sanketsinghdvsjanechef";
// 	cout<<str.size()<<endl;

// 	const char* rs = R"(Line1
// 	line 2
// 	line3)";
// 	cout<<rs<<endl;
// 	return 0;
// }

#include <string>
#include <iostream>
 
int main()
{
    using namespace std::string_literals;
 
    std::string s1 = "abcdef"s + "asd";
    std::cout<<s1<<std::endl;;
    const char16_t* s = u"sanket";
    std::cout<<s;
    std::string_view s2= "as";
    // std::string s2 = "abc\0\0def"s;
    // std::cout << "s1: " << s1.size() << " \"" << s1 << "\"\n";
    // std::cout << "s2: " << s2.size() << " \"" << s2 << "\"\n";
}