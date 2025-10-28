#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;


double get_millis() {
    // Get the current time from the system clock
    auto now = chrono::system_clock::now();

    // Convert the current time to time since epoch
    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds
    auto milliseconds
        = chrono::duration_cast<chrono::milliseconds>(
              duration)
              .count();
    return static_cast<double> (milliseconds);
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
    explicit Point(vector<int> &pin) :p(std::move(pin)) {}


    vector<int> getp() {
        return p;
    }

    void setp(vector<int> &pin) {
        p = pin;
    }
    Point operator=(Point &pin) {
        //Point temp(p);
        p = pin.getp();
        return *this;
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


namespace linalg {
    //Vllt namespace mit matrix
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
        Matrix(Matrix& min) {
            val = min.get_arr();
            nx = val.size();
            ny = val[0].size();
        }

        Matrix(Matrix&& other) noexcept
        : val(std::move(other.val)), nx(other.nx), ny(other.ny) {}

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

        Matrix T() {
            Matrix temp(ny, nx);
            for (int i = 0; i < nx; i++) {
                for (int j = 0; j < ny; j++) {
                    temp.set(j, i, val[i][j]);
                }
            }
            return temp;
        }
        /*
                Matrix inv() {

                }*/

        Matrix& operator=(Matrix in) {
            //swap(size, in.size);
            val.swap(in.get_arr());
            return *this;
        }

        Matrix operator*(Matrix M2) {
            //Optimize to recursive algo -> faster better stronger!

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
        Point operator*(Point pin) {
            auto temp = pin.getp();
            vector<int> res(3);
            for (int i = 0; i < 3; i++) {
                res[i] = val[i][0]*temp[0] + val[i][1]*temp[1] + val[i][2]*temp[2] + val[i][3];
            }
            //Point out(res);
            return Point(res);
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

};

struct Tri_3d {
private:
    vector<Point> p;
    //Point p1, p2, p3;
public:
    Tri_3d() {
        p = vector<Point> (3);
    }
    Tri_3d(const Point& pin1, const Point& pin2, const Point& pin3): p({pin1, pin2, pin3}){}
    Point at(int i) {
        if (i < 3) return p[i];
        else exit(-690);
    }
    void set(Point &pin, int i) {
        if (i < 3) p[i]=pin;
        else exit(-690);
    }

    int get_biggest_z() {
        vector<int> z = {p[0].getp()[2], p[1].getp()[2], p[2].getp()[2]};
        return *max_element(z.begin(), z.end());
    }

    int get_smallest_z() {
        vector<int> z = {p[0].getp()[2], p[1].getp()[2], p[2].getp()[2]};
        return *min_element(z.begin(), z.end());
    }

    sf::VertexArray get_vert() {
        sf::VertexArray out(sf::PrimitiveType::Triangles, 3);
        for (int i = 0; i < 3; i++) {
            out[i].position = sf::Vector2f(static_cast<float>(p[i].getp()[0]), static_cast<float>(p[i].getp()[1]));
        }
        return out;
    }

};
struct Cam {
private:
    linalg::Matrix trans;
    int sx, sy;     //window size in pixels (0, 0, 0) is in middle of screen/view centre
    string mode;    //"perspective" or "parallel"
public:
    Cam(): trans(4, 4) {
        trans = linalg::Matrix(vector<vector<double> >({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}));
        sx = 600;
        sy = 600;
        mode = "parallel";
    }

    Cam(double x, double y, double z, double rx, double ry, double rz, int sxin, int syin): trans(4, 4) {
        trans = linalg::get_homo_trans(x, y, z, rx, ry, rz);
        sx = sxin;
        sy = syin;
        mode = "parallel";
    }

    sf::VertexArray project(Tri_3d &in) {
        sf::VertexArray out(sf::PrimitiveType::Triangles, 3);
        for (int i = 0; i < 3; i++) {
            auto temp = (trans*in.at(i)).getp();
            out[i].position = sf::Vector2f(static_cast<float>(temp[0]), static_cast<float>(temp[1]));
        }
        return out;
    }

    Tri_3d project_tri_3d(Tri_3d &in) {
        Tri_3d out{};
        for (int i=0; i<3; i++) {
            auto temp = trans*in.at(i);
            out.set(temp, i);
        }
        return out;
    }



    void set_rx(double rxin) {
        trans = trans*linalg::get_rx(rxin);
    }
    void set_ry(double ryin) {
        trans = trans*linalg::get_ry(ryin);
    }
    void set_rz(double rzin) {
        trans = trans*linalg::get_rz(rzin);
    }

};

bool comp_tri(Tri_3d a, Tri_3d b) {
    int az = a.get_biggest_z();
    int bz = b.get_biggest_z();
    return az > bz;
}

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
    int sz = 250;
    trs.emplace_back(Point(0, 0, 0), Point(0, 0, sz), Point(0, sz, 0));
    trs.emplace_back(Point(0, 0, sz), Point(0, sz, sz), Point(0, sz, 0));
    trs.emplace_back(Point(0, 0, sz), Point(0, sz, sz), Point(sz, sz, sz));
    trs.emplace_back(Point(0, 0, sz), Point(sz, 0, sz), Point(sz, sz, sz));
    trs.emplace_back(Point(0, sz, 0), Point(0, sz, sz), Point(sz, sz, sz));


    //Cam tests
    sf::RenderWindow win(sf::VideoMode({800, 800}), "pooper");
    win.setFramerateLimit(60);
    double i = 0;
    Cam c(400, 400, 0, 0, -M_PI/2, 0, 600, 600);

    sf::Vector2i old_pos = sf::Mouse::getPosition();

    float fps;
    sf::Clock clock = sf::Clock();
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;

    while (win.isOpen()) {
        i += 0.01;

        //Get mouse data
        sf::Vector2i new_pos = sf::Mouse::getPosition(win); // window is a sf::Window
        sf::Vector2i dpos = old_pos-new_pos;
        old_pos = new_pos;

        //map mouse pos to rotation of object
        c.set_rx(static_cast<double>(dpos.x)/100.0);
        c.set_ry(static_cast<double>(dpos.y)/100.0);


        auto t = c.project(trs[0]);
        auto tzwei = c.project(trs[1]);

        vector<sf::VertexArray> triangles;
        vector<Tri_3d> tris;
        //int i = 0;
        //tris.reserve(trs.size());
        tris.reserve(trs.size());
        for (auto &tri: trs) {
            //Maybe having something like a variable plotting order is good?
            //right now you get artifacts
            //maybe dont plot vertecis that arent on screen
            tris.push_back( c.project_tri_3d(tri));
        }
        //Sort triangles after z value for plot value

        sort(tris.begin(), tris.end(), comp_tri);

        for (auto tri: tris) {
            auto temp = tri.get_vert();
            temp[0].color = sf::Color::Red;
            temp[1].color = sf::Color::Blue;
            temp[2].color = sf::Color::Green;

            triangles.emplace_back(temp);
        }

        // no texture coordinates here, we'll see that later

        // check all the window's events that were triggered since the last iteration of the loop
        while (const optional event = win.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                win.close();
        }

        // clear the window with black color
        win.clear(sf::Color::Black);

        for (auto &tri: triangles) {
            win.draw(tri);
        }
        // end the current frame
        win.display();

        currentTime = clock.getElapsedTime();
        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
        std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
        previousTime = currentTime;
    }
    return 0;
}