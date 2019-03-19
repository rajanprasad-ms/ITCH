class BookConstructor{
    long timestamp;
    Message message;
    OrderBook book;
    OrderPool pool;
    Reader message_reader;
    Writer book_writer;
    Writer message_writer;
    std::string Stock;

    public:
    BookConstructor(std::string inputMessageCSV, std::string outputMessageCSV, std::string outputBookCSV, std::string Stock);
    void next(); // the next message is the main method in the program
    void WriteBookAndMessage;
    void updateBook();
    void updatePool();

}

class Reader{
    std::string fileName;
    std::ifstream file;
    public:
    Reader(std::string fileName);
    std::string getLine(void);
}

class Writer{
    std::string fileName;
    std::ofstream file;
    public:
    Writer(std::string fileName);
    void writeLine(std::string stringToWrite);
}

class Message{
    long timestamp;
    Order order;
    OrderEvent event;
    public:
    // from the message string that comes from the reader, we get order id
    // that we use to look for missing information in the pool
    // This constructur is maybe the most delicate part of the process.
    Message(std::string messageString); 
}

class OrderBook{
    long timestamp;
    std::map<long,long> buySide;
    std::map<long,long> sellSide;
    public:
    // since this should be done at every time, 
    // the datastructure of buySide/sellSide sould 
    // be done accordingly (not sure map is the right one).
    std::string getStringRepresentation(void); // "bestBidPrice,bestBidSize,bestAskPrice,bestAskSize,..."
    void addOrder(long price, long size); // size also negative
}

class OrderPool{
    std::unordered_map<long,Order>;
    public:
    Order findOrderPool(long id);
    void addToOrderPool(Order);
}

class Order{
    long id;
    bool side; // 0 for buy, 1 for sell
    long size; // the LOBSTER report puts here size and remaning size. Dunno why.
    long price;
    public:
    addSize(long size); // also negative
}


