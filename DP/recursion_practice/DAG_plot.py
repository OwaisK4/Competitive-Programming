import graphviz

dot = graphviz.Digraph("DAG")

dot.node('1');
dot.node('2');
dot.node('3');
dot.node('4');

dot.edge('1', '2');
dot.edge('1', '3');
dot.edge('3', '2');
dot.edge('2', '4');
dot.edge('3', '4');

dot.render(view=True)