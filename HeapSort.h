#pragma once
#include "HeadSorter.h"

template<typename T, typename iterator>
struct HeapSort: public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) override {
            auto size = end - begin;
            if (size <= 1) return;
        
            for (auto i = size / 2 - 1; i >= 0; --i) {
                heapify(begin, size, i, comparator);
            }

            for (auto i = size - 1; i > 0; --i) {
                std::swap(*(begin), *(begin + i));
                heapify(begin, i, 0, comparator);
            }
        }

    private:
        void heapify(iterator begin, size_t size, size_t root_index, bool (*comparator)(const T&, const T&)) {
            auto largest = root_index;              // Initialize largest as root
            auto left = 2 * root_index + 1;         // Left child index
            auto right = 2 * root_index + 2;        // Right child index

            if (left < size && comparator(*(begin + largest), *(begin + left))) {
                largest = left;
            }

            if (right < size && comparator(*(begin + largest), *(begin + right))) {
                largest = right;
            }

            if (largest != root_index) {
                std::swap(*(begin + root_index), *(begin + largest));
                heapify(begin, size, largest, comparator); // Recursively heapify the affected subtree
            }
        }
    
public:
    void sort_viz() {
            std::random_device rd;
            std::uniform_int_distribution<int> dist(1, 99);
            std::vector<int> array(100);

            for (auto& elem : array) {
                elem = dist(rd);
            }

            SDL_Window* window = SDL_CreateWindow(
                "HeapSort Visualization",
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                1000, 1000, SDL_WINDOW_SHOWN
            );
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            SDL_RenderSetScale(renderer, 10, 10);

            auto comparator = [](const T& a, const T& b) {
                return a < b; // Min-heap
            };

            // Heapify process visualization
            size_t size = array.size();
            for (auto i = size / 2; i > 0; --i) {
                heapify_viz(array.begin(), size, i - 1, comparator, renderer);
            }

            // Sorting process visualization
            for (auto i = size - 1; i > 0; --i) {
                std::swap(array[0], array[i]);
                visualize(renderer, array, i, 0, "Sorting...");
                heapify_viz(array.begin(), i, 0, comparator, renderer);
            }

            // Pause before closing
            SDL_Delay(2000);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    void heapify_viz(iterator begin, size_t size, size_t root_index, bool (*comparator)(const T&, const T&), SDL_Renderer* renderer) {
            auto largest = root_index;
            auto left = 2 * root_index + 1;
            auto right = 2 * root_index + 2;

            if (left < size && comparator(*(begin + largest), *(begin + left))) {
                largest = left;
            }

            if (right < size && comparator(*(begin + largest), *(begin + right))) {
                largest = right;
            }

            if (largest != root_index) {
                std::swap(*(begin + root_index), *(begin + largest));
                visualize(renderer, std::vector<T>(begin, begin + size), size, root_index, "Heapify...");
                heapify_viz(begin, size, largest, comparator, renderer);
            }
        }

    void visualize(SDL_Renderer* renderer, const std::vector<int>& array, size_t heap_size, size_t current, const std::string& phase) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Черный фон
        SDL_RenderClear(renderer);

        for (size_t i = 0; i < array.size(); ++i) {
            if (i >= heap_size) {
                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255); // Голубой цвет для отсортированных элементов
            } else if (i == current) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Красный для текущего элемента
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Белый для остальных
            }

            SDL_RenderDrawLine(renderer, i, 99, i, 99 - array[i]);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

};
