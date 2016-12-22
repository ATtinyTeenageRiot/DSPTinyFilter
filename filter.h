
class SecondOrderSection
{
  private:
    int b0, b1, b2, a1, a2;
    long zx[2] = {0, 0}; // Q31
    long zy[2] = {0, 0}; // Q31

  public:
    SecondOrderSection(int b0, int b1, int b2, int a1, int a2);
    long process(long x);
    
};

class LeakyAverage
{
  private:
    long alpha, one_m_alpha;
    long zy;
    int Q;

  public:
    LeakyAverage(int _alpha, int _Q)
    {
      Q = _Q;
      alpha = _alpha;
      zy = 0;
      one_m_alpha = (1l << (Q-1)) - alpha;
    }
    
    //inline long process(long x);
    inline long process(long x)
    {
      zy *= alpha;
      zy += one_m_alpha*x;
      zy >>= Q;
    
      return zy;
    }

    // Reset buffer
    void reset(void)
    {
      zy = 0;
    }

};

