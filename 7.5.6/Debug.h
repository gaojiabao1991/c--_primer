class Debug {
   public:
    constexpr Debug(bool hw, bool io, bool other) : hw(hw), io(io), other(other) {}
    constexpr Debug(bool b) : hw(b), io(b), other(b) {}

    constexpr bool any() { return hw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

   private:
    bool hw;
    bool io;
    bool other;
};