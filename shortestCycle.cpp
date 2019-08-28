/*Exercise from codeforce: https://codeforces.com/contest/1205/problem/B
//Good to know: https://es.wikipedia.org/wiki/Operador_a_nivel_de_bits
*Algorithm:
- Generate the graph with the following struct:
struct nodoGraph{
    int dato;
    nodoGraph[] listOfConnectedNodes;
}
- For each node search each path to himself.
- For each one calculate the length and return that.
- If any return -1.
*Take in count that two nodes are connected if a1(binary) AND a2(binary) != 0 *
*/

int main()
{
}