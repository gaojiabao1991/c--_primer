class No_default {
   public:
    No_default(int i) : i(i) {}
    // No_default() : No_default(0) {}

   private:
    int i;
};

class C {
   public:
    C() = default;

   private:
    No_default nd;
};