#include <iostream>

template <class T>
class Array
{
    //---------------//
    //    Private    //
    //---------------//
private:
    T* arr;
    int size;
    int grow;
    int count;

    //----------------//
    //     Public     //
    //----------------//
public:
    //----------------//
    //  Constructors  //
    //----------------//
    Array(T* arr, int size)
    {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
        grow = size;
        count = size;
    }
    Array(const Array &other)
    {
        this->size = other.size;
        this->grow = other.grow;
        this->count = other.count;
        this->arr = new T[this->size];
        for (int i = 0; i < this->size; i++)
            arr[i] = other.arr[i];
    }
    ~Array(){ delete[] arr; }

    //---------------//
    //    Methods    //
    //---------------//

        //--------//
        //  Size  //
        //--------//
    int getSize() const { return size; }
    void setSize(int size, int grow)
    {
        T* temp = new T[size];
        if (this->size < size)
        {
            for (int i = 0; i < this->size; i++)
                temp[i] = this->arr[i];
            for (int i = this->size; i < size; i++)
                temp[i] = T();
        }

        else if (this->size > size)
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        this->size = size;
        this->arr = temp;
        this->grow = grow;
    }
    void setSize(int size)
    {
        T* temp = new T[size];
        if (this->size < size)
        {
            for (int i = 0; i < this->size; i++)
                temp[i] = this->arr[i];
            for (int i = this->size; i < size; i++)
                temp[i] = T();
        }

        else if (this->size > size)
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        this->size = size;
        this->arr = temp;
    }
    void freeExtra()
    {
        T* temp = new T[count];
        if (count < size)
            for (int i = 0; i < count; i++)
                temp[i] = arr[i];
        else
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = count;
    }
    void removeAll()
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
        count = 0;
        grow = 0;
    }
        //----------//
        //  Status  //
        //----------//
    T* getData() {return arr;}
    const T* getData() const {return arr;}
    int getUpperBound() const { return count; }
    bool isEmpty() const
    {
        if (count == 0)
            return true;
        return false;
    }
        //-----------//
        //  Element  //
        //-----------//
    T getAt(int index) const
    {
        if (index > size && index > 0)
        {
            return T();
        } else
        {
            return arr[index];
        }
    }
    void setAt(int index, T var)
    {
        if (index < size && index >= 0)
            arr[index] = var;
    }
    void insertAt(int index, T var)
    {
        if (index < size && index >= 0)
        {
            if (count + 1 >= size)
                setSize(size + grow);
            for (int i = count; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = var;
            count++;
        }
    }
    void removeAt(int index)
    {
        if (index < count && index >= 0)
        {
            for (int i = index; i < count - 1; i++)
                arr[i] = arr[i + 1];
            count--;
            arr[count] = T();
        }
    }
    T operator[](int index) const
    {
        return getAt(index);
    }
    T& operator[](int index)
    {
        if (index < size && index >= 0)
            return arr[index];
        return arr[0];
    }
        //------------//
        //  Modifies  //
        //------------//
    void add(T var)
    {
        if (count == size)
        {
            setSize(size + grow);
        }
        arr[count] = var;
        count++;
    }
    void append(Array other)
    {
        int newCount = this->count + other.count;
        if (this->size < newCount)
        {
            setSize(newCount);
        }

        for (int j = 0; j < other.count; j++)
        {
            this->arr[this->count + j] = other.arr[j];
        }
        this->count = newCount;
    }
    Array& operator=(const Array& other)
    {
        if (this == &other) return *this;

        delete[] arr;

        arr = new T[other.count];
        for (int i = 0; i < other.count; i++)
        {
            arr[i] = other.arr[i];
        }
        size = other.count;
        grow = other.grow;
        count = other.count;

        return *this;
    }

    void print() const
    {
        if (isEmpty() == 0)
        {
            for (int i = 0; i < size; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Array is clear" << std::endl;
        }
    }
};

int main()
{
    int const SIZE = 3;
    int arr[SIZE] = {30, 10, 20};
    Array<int> myArr1(arr, SIZE);

    return 0;
}