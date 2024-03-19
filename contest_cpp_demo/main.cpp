#include <iostream>
#include <set>
#include <random>
#include <vector>

class Vector3D
{
    public:
    /* class methods */
    // Task 1, empty constructor
    Vector3D() : _x(0.0), _y(0.0), _z(0.0) { v.push_back(1);}
    // Task 2, constructor with arguments
    Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {v.push_back(1); }
    // Task 3, copy constructor
    Vector3D(const Vector3D& v2) : _x(v2._x), _y(v2._y), _z(v2._z) {v.push_back(1); }
    Vector3D(double x) : _x(x), _y(x), _z(x) { }
    
    // Task 4. Getters and setters (define for other attributes)
    // getter
    double getX() const
    {
        return _x;
    }
    // setter
    void setX(double x)
    {
        _x = x;
    }
    double getY() const
    {
        return _y;
    }
    // setter
    void setY(double y)
    {
        _y = y;
    }
    double getZ() const
    {
        return _z;
    }
    // setter
    void setZ(double z)
    {
        _z = z;
    }
    
    Vector3D operator+(const Vector3D& v2) const {
        // temp = v1(this) + v2;
        return Vector3D(_x + v2._x, _y + v2._y, _z + v2._z);
    }

    friend double operator* (const Vector3D& v1, const Vector3D& v2);

    friend Vector3D operator* (const Vector3D& v1, double d);
    friend bool operator<(const Vector3D& v1, const Vector3D& v2);
    friend bool operator>(const Vector3D& v1, const Vector3D& v2);
    friend std::ostream& operator<<(std::ostream& ofs, const Vector3D v);
    friend std::istream& operator>> (std::istream& in, Vector3D& v1);
    // Task 8. Magnitude
    double magnitude() const {
        return sqrt(_x*_x + _y*_y+_z*_z);
    }
    
    private:
    /* attributes */
        double _x;
        double _y;
        double _z;
        std::vector<int> v;
};

// // Task 6. Operator * (dot product)
double operator* (const Vector3D& v1, const Vector3D& v2) {
    return v1._x * v2._x + v1._y * v2._y + v1._z * v2._z; 
}

// // Task 7. Operator * (scalar product)
// // (can be defined here or inside the class)
Vector3D operator* (const Vector3D& v1, double d) {
    return Vector3D(v1._x * d, v1._y * d, v1._z * d);
}

// // Task 9. Operator <
// // (can be defined here or inside the class)
bool operator<(const Vector3D& v1, const Vector3D& v2) {
    return v1.magnitude() < v2.magnitude();
}

bool operator>(const Vector3D& v1, const Vector3D& v2) {
    return v1.magnitude() > v2.magnitude();
}


// // Task 10. Operator << (printing)
// // (can't be defined inside the class)
// // Use definition from previous workshops
std::ostream& operator<<(std::ostream& ofs, const Vector3D v) {
    ofs << "(" << v._x << ","<< v.getY() << ","<< v.getZ() << ")" << "\n";
    return ofs;
}


std::istream& operator>> (std::istream& in, Vector3D& v1)
{
    in >> v1._x >> v1._y >> v1._z;
    return in;
}


void fillMultiset(size_t n, std::multiset<Vector3D>& mset)
{
    // generating random numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-1, 1);
    
    
    // loop, add a new element to the multiset n times
    for (int i = 0; i < n; i++) {
        double x = distr(gen);
        double y = distr(gen);
        double z = distr(gen);
        mset.insert(Vector3D(x,y,z));
    }
    
}


int main()
{
    //std::vector<Vector3D> vec_vec;
    // Vector3D v1(0, 1, 2);
    // Vector3D v2(1, 2, 3);
    // Vector3D sum = v1 + v2;
    // vec_vec.push_back(v1);
    // vec_vec.push_back(v2);
    // vec_vec.push_back(sum);
    // std::sort(vec_vec.begin(), vec_vec.end(), std::less<Vector3D>()); // < >
    // for (int i = 0; i < vec_vec.size(); i++) {
    //     std::cout << vec_vec[i];
    // }
    // Final task
    // Part 1. Fill a multiset of Vector3D objects with random vectors.
    std::multiset<Vector3D> s;
    const size_t setSize = 100;
    fillMultiset(100, s);
    
    // Part 2. Print all elements of the multiset
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it;
    }
    
    // Part 3. Calculate and print the average of all magnitudes of vectors
    double averageMagnitude = 0;

    for (auto it = s.begin(); it != s.end(); it++) {
        averageMagnitude += it->magnitude();
    }
    averageMagnitude /= (s.size());
    std::cout << "Average magnitude is " << averageMagnitude << std::endl;
    
    return 0;
}
