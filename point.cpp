#include "point.h"

CImg <char> Point::barrido_vector(CImg<> &picturee, int cominezo) const {
    CImg <char> DOULE(picturee.width(),picturee.height());
    FOR(i,0,picturee.width())
    {
        FOR(j,0,picturee.height())
        {
            int r = (int)picturee(i, j, 0),
                g = (int)picturee(i, j, 1),
                b = (int)picturee(i, j, 2);
            DOULE(i, j) = (char) ((r + g + b) / 3 > cominezo ? 0 : 255);

        }
    }
    return DOULE;
}

void Point::verPicture(const string& road_picture, int cominezo) {
    ifstream road_file(road_picture.c_str());
    string ruta;
    while (getline(road_file, ruta)) {
        CImg <float> imagenInicial(ruta.c_str());
        //La Magia de los puntos
        CImg <char> imagenFinal = barrido_vector(imagenInicial, cominezo);
        //FIN de la MAGIC
        this->picture_.emplace_back(imagenFinal);
        this->num_picture_++;
    }
    road_file.close();
}

void Point::point_out(float distance_IMG) {
    int point_totality = 0;
    FOR(IMG,0,this->num_picture_)
    {
        CImg <char> actuality_picture = this->picture_[IMG];
        vector <vec3f> point_pictur_vec;
        cimg_forXY(actuality_picture, x, y) {
                if (to_string(actuality_picture.atXYZC(x, y, 1, 1))[0] != to_string(actuality_picture.atXYZC(x + 1, y, 1, 1))[0]) {
                    if (to_string(actuality_picture.atXYZC(x, y, 1, 1))[0] == '0') {
                        vec3f punto3D((float)x - 256, (float)y - 256, (float)IMG * distance_IMG);
                        point_pictur_vec.emplace_back(punto3D);
                    } else {
                        vec3f punto3D((float)x - 255, (float)y - 256, (float)IMG * distance_IMG);
                        point_pictur_vec.emplace_back(punto3D);
                    }
                }
            }
        this->point_.emplace_back(point_pictur_vec);
        cout << "Se tomo:" <<point_pictur_vec.size() << " point -> Imagen " << IMG++ << endl;
        point_totality += (int)point_pictur_vec.size();
    }
    cout << "Se tomo: " << point_totality << " point totality" << endl;
}

void Point::guardar_point(const string& camino) {
    cout << "Inicio para Guardar: " << endl;
    fstream filePoint;
    filePoint.open(camino.c_str(), ios::out);
    for (auto &IMG: this->point_)
        for (auto &punto: IMG) filePoint << punto.x_ << ' ' << punto.y_ << ' ' << punto.z_ << endl;;
    filePoint.close();
    cout << "ACABO ... SE GUARDO TODO" << endl;
}

void Point::load_file(const string &camino_Point) {
    ifstream file;
    file.open(camino_Point.c_str(), ios::in);
    string leidoxlinea;
    vector <vec3f> puntosImagen;
    while (!file.eof()) {
        getline(file, leidoxlinea);
        float x, y, z;
        sscanf(leidoxlinea.c_str(), "%f %f %f", &x, &y, &z);
        vec3f punto3D(x, y, z);
        puntosImagen.emplace_back(punto3D);
        //cout<<"Leido.."<<endl;
    }
    this->point_.emplace_back(puntosImagen);
}
//Prueba
