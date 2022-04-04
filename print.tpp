template<typename T>
void printElement(T el, const int& width){
    const char separator = ' ';
    std::cout << std::left << std::setw(width) << std::setfill(separator) << el;
}
