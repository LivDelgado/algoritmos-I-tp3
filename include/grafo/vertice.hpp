#ifndef VERTICE
#define VERTICE

namespace grafo {
    class Vertice {
        private:
            int u;
            int v;

        public:
            Vertice();
            Vertice(int u, int v);

            int getU();
            int getV();

            void setU(int u);
            void setV(int v);
    };

}

#endif