#include <iostream>

static int array[100001];
static int placement[100001];
static void solve(int case_num)
{
	int res, cur, s, k, q, n, leftDoor, rightDoor;
	std::cin >> n >> q;
	for (int i = 0; i < n - 1; ++i)
	{
		std::cin >> array[i];
	}
	// the i-th door is between the i-th room and the i+1-th room
	// cur is the number of the room
	// left- and right-door are the first doors that are locked
	
	
	for (int i = 0; i < q; ++i)
	{
		std::cin >> s >> k;
		--s;
		// don't forget to return s + 1 in the end

		// s = 1, k = 2, 30 60 50 
		leftDoor = s - 1; rightDoor = s;
		cur = s;
		while (--k > 0)
		{
			if (leftDoor == -1) // all the doors on the left were unlocked
				cur = ++rightDoor;
			else if (rightDoor == n - 1) // all the doors on the right were unlocked
				cur = --leftDoor;
			else if (array[leftDoor] < array[rightDoor])
				cur = leftDoor--;
			else
				cur = ++rightDoor;
			
			if (array[leftDoor] )
			
		}
	}


	std::cout << "Case #" << case_num << ": " << res << std::endl;
}

int main()
{
	int T; std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve(i + 1);
}