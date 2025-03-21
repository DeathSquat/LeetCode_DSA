import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, Integer> inDegree = new HashMap<>();
        Map<String, List<String>> graph = new HashMap<>();
        Set<String> available = new HashSet<>(Arrays.asList(supplies));
        List<String> result = new ArrayList<>();
        
        // Initialize graph and in-degree for recipes
        for (int i = 0; i < recipes.length; i++) {
            String recipe = recipes[i];
            inDegree.put(recipe, ingredients.get(i).size()); // Count needed ingredients
            
            for (String ing : ingredients.get(i)) {
                graph.computeIfAbsent(ing, k -> new ArrayList<>()).add(recipe);
            }
        }

        // Queue for topological sorting (starting with available supplies)
        Queue<String> queue = new LinkedList<>(available);
        
        while (!queue.isEmpty()) {
            String current = queue.poll();
            
            // If current is a recipe, add it to the result
            if (inDegree.containsKey(current)) {
                result.add(current);
            }
            
            // Reduce in-degree for dependent recipes
            if (graph.containsKey(current)) {
                for (String nextRecipe : graph.get(current)) {
                    inDegree.put(nextRecipe, inDegree.get(nextRecipe) - 1);
                    
                    // If all ingredients are available, we can make this recipe
                    if (inDegree.get(nextRecipe) == 0) {
                        queue.offer(nextRecipe);
                    }
                }
            }
        }

        return result;
    }
}
