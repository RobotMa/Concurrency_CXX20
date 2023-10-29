class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton instance; // Guaranteed to be destroyed.
                               // Instantiated on first use.
    return instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

private:
  Singleton() = default; // Constructor is private
  ~Singleton() = default; // Destructor is private
};
