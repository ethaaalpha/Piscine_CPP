class PmergeMe
{
private:
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe &parent);
	PmergeMe(const PmergeMe &parent);
};
