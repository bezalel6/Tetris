#define SINGLETON(name, ...)                      \
   public:                                        \
    static name& getInstance() {                  \
        static name instance = name(__VA_ARGS__); \
        return instance;                          \
    };
