#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

namespace linalg {//Vllt namespace mit matrix
    struct Matrix {
    private:
        vector<vector<double>> val;
        int nx, ny;


    public:
        Matrix(const int nxin, const int nyin) {
            nx = nxin;
            ny = nyin;
            val = vector<vector<double>> (nx, vector<double>(ny));
        }
        Matrix(Matrix &min) {
            val = min.get_arr();
            nx = val.size();
            ny = val[0].size();
        }
        explicit Matrix(const vector<vector<double>> &in) {
            val = in;
            nx = val.size();
            ny = val[0].size();
        }

        //explicit Matrix(const vector<vector<double>> & vector);

        double at(int x, int y) {
            if (x > nx) {
                cout << "X OUT OF BOUNDS!" << endl;
                exit(0);
            }
            if (y > ny) {
                cout << "Y OUT OF BOUNDS!" << endl;
                exit(0);
            }
            return val[x][y];
        }
        void set(int i, int j, double valin) {
            val[i][j] = valin;
        }
        vector<vector<double>>& get_arr() {
            return val;
        }

        Matrix& operator=(Matrix in) {
            //swap(size, in.size);
            val.swap(in.get_arr());
            return *this;
        }

        Matrix operator*(Matrix M2) {
            auto m1=val, m2=M2.get_arr();
            int r1=m1.size(), c1=m1[0].size(), r2=m2.size(), c2=m2[0].size();
            Matrix out(r1, c2);
            double temp=0;
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    out.set(i, j, 0);
                    for (int k = 0; k < r2; k++) {
                        temp = out.at(i, j);
                        temp += m1[i][k] * m2[k][j];
                        out.set(i, j, temp);
                    }
                }
            }
            return out;
        }

    };

    Matrix get_rx(double alpha) {
        vector<vector<double>> temp = {{1, 0, 0, 0},{0, cos(alpha), -sin(alpha), 0}, {0, sin(alpha), cos(alpha), 0}, {0, 0, 0, 1}};
        return Matrix(temp);
    }
    Matrix get_ry(double alpha) {
        vector<vector<double>> temp = {{cos(alpha), 0, -sin(alpha), 0}, {0, 1, 0, 0}, {sin(alpha), 0, cos(alpha), 0}, {0, 0, 0, 1}};
        return Matrix(temp);
    }
    Matrix get_rz(double alpha) {
        vector<vector<double>> temp = {{cos(alpha), -sin(alpha), 0, 0},{sin(alpha),  cos(alpha), 0, 0}, {0, 0, 1, 0},  {0, 0, 0, 1}};
        return Matrix(temp);
    }
    Matrix get_homo_trans(double x, double y, double z, double rx, double ry, double rz) {
        Matrix temp(vector<vector<double>>({{1, 0, 0, x}, {0, 1, 0, y}, {0, 0, 1, z}, {0, 0, 0, 1}}));
        return temp * get_rx(rx) * get_ry(ry) * get_rz(rz);
    }
}

struct Point {
protected:
    vector<int> p;
public:
    Point() {
        p = {0, 0, 0};
    }
    Point(int xin, int yin, int zin) {
        p = {xin, yin, zin};
    }
    vector<int> getp() {
        return p;
    }

    void setp(vector<int> &pin) {
        p = pin;
    }
    Point operator=(Point &p) {
        //Point temp(p);
        return p;
    }
};

struct orientation_3d: private Point {
private:
    vector<double> rot;
public:
    orientation_3d() {
        p = {0, 0, 0};
    }
};
struct Tri_3d {
private:
    Point p1, p2, p3;
public:
    Tri_3d(Point pin1, Point pin2, Point pin3): p1(), p2(), p3(){
        p1 = pin1;
        p2 = pin2;
        p3 = pin3;
    }
};
using namespace linalg;
int main() {
    //test of matmul
    vector<vector<double>> t1 = {{1, 0}, {0, 1}};
    vector<vector<double>> t2 = {{6, 9}, {9, 6}};
    Matrix M1 (t1);
    Matrix M2(t2);
    Matrix M3(M1*M2);

    Matrix M4 = get_rx(0);
    Matrix M5 = get_homo_trans(1, 2, 3, 0, 0, 0);
    cout << "cunt" << endl;

    //Würfel als menge von dreiecken definieren
    //Kamera als extra koordinatensystem mit begrenzungen für die Darstellung
    //-> transformation aller Punkte in system der Kamera -> z-achse=0
    //-> plot der resultierenden ebenen dreiecke als vector mit sf::VertexArray tri(sf::PrimitiveType::Triangles, 3);
    vector<Tri_3d> trs;

    //manueller input des Würfels
    trs.emplace_back(Point(0, 0, 0), Point(0, 0, 1), Point(0, 0, 1));
    trs.emplace_back(Point(0, 0, 1), Point(0, 1, 1), Point(0, 1, 0));
    trs.emplace_back(Point(0, 0, 1), Point(0, 1, 1), Point(1, 1, 1));
    trs.emplace_back(Point(0, 0, 0), Point(0, 0, 1), Point(0, 0, 1));


    /*
    sf::RenderWindow win(sf::VideoMode({800, 600}), "pooper");
    win.setFramerateLimit(60);

    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(100.f, 100.f);

    // define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

    // no texture coordinates here, we'll see that later
    while (win.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const optional event = win.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                win.close();
        }

        // clear the window with black color
        win.clear(sf::Color::Black);
        win.draw(triangle);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        win.display();
    }
    */
    return 0;
}