import java.util.*;

class ElectricBoardManager 
{
    private Map<String, List<Integer>> boardMap;

    public ElectricBoardManager() 
	{
        boardMap = new HashMap<>();
    }

    public void addReading(String boardId, List<Integer> readings) 
	{
        if (boardMap.containsKey(boardId)) 
		{
            boardMap.get(boardId).addAll(readings);
        } 
		else 
		{
            boardMap.put(boardId, new ArrayList<>(readings));
        }
    }

    public double getAveragePowerConsumption(String boardId, int startingRange, int endingRange) 
	{
        if (startingRange > endingRange) 
		{
            int temp = startingRange;
            startingRange = endingRange;
            endingRange = temp;
        }

        if (!boardMap.containsKey(boardId)) 
		{
            return 0.0;
        }

        List<Integer> readings = boardMap.get(boardId);
        int sum = 0;
        int count = 0;

        for (int value : readings) 
		{
            if (value >= startingRange && value <= endingRange) 
			{
                sum += value;
                count++;
            }
        }

        if (count == 0) 
		{
            return 0.0;
        }

        return (double) sum / count;
    }
}

public class IPAApr10B 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        ElectricBoardManager manager = new ElectricBoardManager();

        int n = Integer.parseInt(sc.nextLine().trim());

        for (int i = 0; i < n; i++) 
		{
            String boardId = sc.nextLine().trim();
            int readingCount = Integer.parseInt(sc.nextLine().trim());

            List<Integer> readings = new ArrayList<>();
            for (int j = 0; j < readingCount; j++) 
			{
                readings.add(Integer.parseInt(sc.nextLine().trim()));
            }

            manager.addReading(boardId, readings);
        }

        String queryBoardId = sc.nextLine().trim();
        int startingRange = Integer.parseInt(sc.nextLine().trim());
        int endingRange = Integer.parseInt(sc.nextLine().trim());

        double avg = manager.getAveragePowerConsumption(queryBoardId, startingRange, endingRange);

        System.out.println("Average power consumption for board " + queryBoardId + " from " + startingRange + " to " + endingRange + ": " + avg);

        sc.close();
    }
}