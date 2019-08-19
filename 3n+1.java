
public static final int cacheSize = 1000000;
private static long[] cache = new long[cacheSize];

static {
  cache[1] = 1;
  cache[2] = 2;
  cache[4] = 3;
  cache[8] = 4;
  cache[16] = 5;
}

public static void mainAlgorithm(int n)
{
    cout << n << endl;
    if (n != 1)
    {
        if (n % 2 == 0)
        {
            n = 3 * n + 1;
            mainAlgorithm(n);
        }
        else
        {
            n = n / 2;
            mainAlgorithm(n);
        }
    }
}

public static long cycleLength(long n) {
     // Return cycle length from cache if already calculated
    if (n < cacheSize && cache[(int) n] != 0) {
        return cache[(int) n];
    }

    long length = 1 + cycleLength(n % 2 == 0 ? n / 2 : 3 * n + 1);

    if (n < cacheSize) {
        cache[(int) n] = length;
    }

  return length;
}

public static long maxCycleLength(long start, long end) {

    long min = Math.min(start, end);
    long max = Math.max(start, end);
    long maxCycleLength = 0;

    for (long i = min; i <= max; i++) {
        long cycleLength = cycleLength(i);
        if (cycleLength > maxCycleLength) {
            maxCycleLength = cycleLength;
        }
    }

    return maxCycleLength;
}

//
public static void main(final String[] args) {

  try (
      final Scanner in = new Scanner(System.in);
      PrintWriter out = new PrintWriter(System.out);
  ) {

    while (in.hasNextInt()) {
      int i = in.nextInt();
      int j = in.nextInt();
      long resp = maxCycleLength(i, j);
      out.print(i + " " + j + " " + resp);
    }
  }
}