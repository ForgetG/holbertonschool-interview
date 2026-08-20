#!/usr/bin/python3
"""Recursively count keywords in hot Reddit post titles."""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Print counts of keywords found in hot Reddit post titles."""
    if counts is None:
        counts = {}
        for word in word_list:
            word = word.lower()
            counts[word] = counts.get(word, 0) + 1

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "holberton-count-it/1.0"}
    params = {"limit": 100}

    if after is not None:
        params["after"] = after

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    posts = data.get("children", [])

    for post in posts:
        title = post.get("data", {}).get("title", "").lower()
        words = title.split()

        for word in counts:
            counts[word] += (
                words.count(word) * (word_list_count(word_list, word) - 1)
            )

    after = data.get("after")

    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    original_counts = {}
    for word in word_list:
        word = word.lower()
        original_counts[word] = original_counts.get(word, 0) + 1

    results = []
    for word in counts:
        value = counts[word] - original_counts[word]
        if value > 0:
            results.append((word, value))

    results.sort(key=lambda item: (-item[1], item[0]))

    for word, value in results:
        print("{}: {}".format(word, value))


def word_list_count(word_list, target):
    """Return how often target occurs in word_list, ignoring case."""
    count = 0

    for word in word_list:
        if word.lower() == target:
            count += 1

    return count
