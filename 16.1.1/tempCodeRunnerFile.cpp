bool operator<(const Sales_data& a, const Sales_data& b) {
    return a.isbn() < b.isbn();
}